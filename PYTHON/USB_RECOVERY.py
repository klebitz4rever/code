
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
USB HID 键盘报文还原脚本 (CTF / Wireshark USB 键鼠题通用)

功能：
    从 Wireshark 导出的文本 / tshark 字段导出中，自动提取 USB HID 键盘的
    "Leftover Capture Data" 8 字节报文，按 HID Usage ID (Page 0x07) 键码表
    还原成真实击键字符串。支持修饰键(Shift)、退格、去重复上报等处理。

输入格式(自动识别，二者皆可)：
    1) Wireshark 报文列表拷贝(含 "Leftover Capture Data: 0000080000000000")
    2) tshark 字段导出，每行一段纯 hex (如 00:00:08:00:00:00:00:00 或 0000080000000000)

用法：
    python3 hid_keyboard_recover.py keyboard.txt [keyboard.txt ...]
    python3 hid_keyboard_recover.py keyboard.txt --detail   # 打印逐包明细
"""

import sys
import re

# ---- HID Usage ID (Keyboard/Keypad, Page 0x07) 键码 -> 字符 ----
# 未加 Shift 的普通映射
KEYMAP = {
    0x04: 'a', 0x05: 'b', 0x06: 'c', 0x07: 'd', 0x08: 'e', 0x09: 'f',
    0x0A: 'g', 0x0B: 'h', 0x0C: 'i', 0x0D: 'j', 0x0E: 'k', 0x0F: 'l',
    0x10: 'm', 0x11: 'n', 0x12: 'o', 0x13: 'p', 0x14: 'q', 0x15: 'r',
    0x16: 's', 0x17: 't', 0x18: 'u', 0x19: 'v', 0x1A: 'w', 0x1B: 'x',
    0x1C: 'y', 0x1D: 'z',
    0x1E: '1', 0x1F: '2', 0x20: '3', 0x21: '4', 0x22: '5', 0x23: '6',
    0x24: '7', 0x25: '8', 0x26: '9', 0x27: '0',
    0x28: '\n',            # Return / Enter
    0x29: '\x1b',          # Escape
    0x2A: '\x08',          # Backspace
    0x2B: '\t',            # Tab
    0x2C: ' ',             # Space
    0x2D: '-', 0x2E: '=', 0x2F: '[', 0x30: ']', 0x31: '\\',
    0x33: ';', 0x34: "'", 0x35: '`', 0x36: ',', 0x37: '.', 0x38: '/',
    0x64: '\\',            # Non-US # (ISO)
}
# 按住 Shift 时的映射(字母用大写，数字/符号用其上档字符)
SHIFTMAP = {
    0x1E: '!', 0x1F: '@', 0x20: '#', 0x21: '$', 0x22: '%', 0x23: '^',
    0x24: '&', 0x25: '*', 0x26: '(', 0x27: ')',
    0x2D: '_', 0x2E: '+', 0x2F: '{', 0x30: '}', 0x31: '|',
    0x33: ':', 0x34: '"', 0x35: '~', 0x36: '<', 0x37: '>', 0x38: '?',
}

# 修饰键位(报文第 0 字节)
MOD_CTRL_L  = 0x01
MOD_SHIFT_L = 0x02
MOD_ALT_L   = 0x04
MOD_GUI_L   = 0x08
MOD_CTRL_R  = 0x10
MOD_SHIFT_R = 0x20
MOD_ALT_R   = 0x40
MOD_GUI_R   = 0x80

BACKSPACE   = 0x2A
ENTER       = 0x28

HEX_CLEAN = re.compile(r'[^0-9a-fA-F]')
LCD_RE    = re.compile(r'Leftover Capture Data:\s*([0-9a-fA-F:]+)')


def extract_reports(text):
    """从任意文本中提取所有 HID 报文(hex 字节串列表)。"""
    raw_tokens = []
    found = LCD_RE.findall(text)
    if found:
        # Wireshark 报文列表拷贝格式
        raw_tokens = found
    else:
        # tshark 字段导出：每行一段 hex(可能带冒号)
        for line in text.splitlines():
            line = line.strip()
            if not line:
                continue
            hex_part = re.sub(r'^.*?:\s*', '', line)
            if re.fullmatch(r'[0-9a-fA-F:]+', hex_part) and len(HEX_CLEAN.sub('', hex_part)) >= 16:
                raw_tokens.append(hex_part)
    reports = []
    for tok in raw_tokens:
        h = HEX_CLEAN.sub('', tok)
        if len(h) < 16:
            continue
        b = [int(h[i:i + 2], 16) for i in range(0, 16, 2)]
        reports.append(b)
    return reports


def decode(reports, detail=False):
    """把 HID 报文序列还原成击键字符串。"""
    out = []
    prev_sig = None
    lines = []
    for idx, rep in enumerate(reports, 1):
        modifier = rep[0]
        keys = [k for k in rep[2:8] if k != 0x00]
        sig = (modifier, tuple(keys))
        # 跳过空闲报文(全 0)
        if not keys and modifier == 0:
            if detail:
                lines.append('#%d  <idle>' % idx)
            prev_sig = None
            continue
        # 去除"按住不放"产生的连续重复上报
        if sig == prev_sig:
            if detail:
                lines.append('#%d  <repeat ignored> mod=%02x keys=%s'
                             % (idx, modifier, keys))
            continue
        prev_sig = sig

        shift = bool(modifier & (MOD_SHIFT_L | MOD_SHIFT_R))
        ctrl  = bool(modifier & (MOD_CTRL_L  | MOD_CTRL_R))
        alt   = bool(modifier & (MOD_ALT_L   | MOD_ALT_R))

        ch_text = ''
        key_desc = []
        for kc in keys:
            if kc == BACKSPACE:
                if out:
                    out.pop()
                key_desc.append('Backspace')
                continue
            if shift and kc in SHIFTMAP:
                ch = SHIFTMAP[kc]
            elif kc in KEYMAP:
                ch = KEYMAP[kc]
            else:
                ch = ''
            if ch:
                if ctrl or alt:
                    ch_text += ch
                else:
                    out.append(ch)
            key_desc.append('%s0x%02x' % ('S-' if shift else '', kc))
        if detail:
            flags = ''.join(['C' if ctrl else '', 'A' if alt else '',
                             'S' if shift else ''])
            lines.append('#%-4d mod=%s keys=%s -> %r'
                         % (idx, flags or '-', ' '.join(key_desc), ch_text))
    return ''.join(out), lines


def main(argv):
    args = [a for a in argv if not a.startswith('-')]
    detail = '-d' in argv or '--detail' in argv
    if not args:
        print(__doc__)
        print('用法: python3 hid_keyboard_recover.py <keyboard.txt> [--detail]')
        return 1
    for path in args:
        with open(path, 'r', encoding='utf-8', errors='ignore') as f:
            text = f.read()
        reports = extract_reports(text)
        result, lines = decode(reports, detail)
        print('=' * 60)
        print('输入文件 : %s' % path)
        print('HID报文数: %d' % len(reports))
        if detail:
            print('-' * 60)
            print('\n'.join(lines))
        print('-' * 60)
        print('还原结果 :')
        print(result)
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))