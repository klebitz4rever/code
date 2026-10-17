# 这是一个简单的验证脚本
# 请尝试破解它，获得真正的 flag

secret = [97, 108, 105, 101, 110] 
# 提示：这些数字在 ASCII 码表中代表字母

input_flag = input("Please enter the flag: ")

# 程序会把 flag 的特定部分提取出来，与 secret 列表比对
check_part = input_flag[5:10] 

is_correct = True
for i in range(len(check_part)):
    # 核心比对逻辑
    if ord(check_part[i]) != secret[i]:
        is_correct = False

if is_correct:
    print("Correct! You found the key.")
    print(f"flag{{{check_part}}}")
else:
    print("Wrong! Try again.")