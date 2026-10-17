from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
import base64

key_hex = "93db05de0473f0bee941dd9a5b16346cd7158d4e5e1e6f86ea24f82810df3eaa"
iv_hex  = "c920c9cebe84b08576750040aeb65cbf"

key = bytes.fromhex(key_hex)
iv  = bytes.fromhex(iv_hex)

# 这里替换成 zip 里那个密文文件的 Base64 或 Hex
cipher_b64 = "这里填密文Base64"
ct = base64.b64decode(cipher_b64)

cipher = AES.new(key, AES.MODE_CBC, iv)
pt = unpad(cipher.decrypt(ct), 16)
print(pt)