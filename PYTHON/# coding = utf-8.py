# 扩展欧几里得算法：用来计算 a 和 b 的最大公约数，同时返回贝祖系数 x 和 y
# 使得 a * x + b * y = gcd(a, b)
def extended_gcd(a, b):
    # 基本情况，如果 b == 0，则 gcd(a, b) = a, x = 1, y = 0
    if b == 0:
        return a, 1, 0
    # 递归调用扩展欧几里得算法，获取 gcd(a, b) 和贝祖系数 x, y
    gcd, x1, y1 = extended_gcd(b, a % b)
    # 更新贝祖系数 x 和 y，返回新的系数
    x = y1
    y = x1 - (a // b) * y1
    return gcd, x, y


# 求解模逆元：即求解 x 使得 a * x ≡ 1 (mod m)
def mod_inverse(a, m):
    # 调用扩展欧几里得算法，获取 gcd(a, m), x, y
    gcd, x, y = extended_gcd(a, m)

    # 如果 a 和 m 不是互质的，说明没有模逆元
    if gcd != 1:
        raise ValueError(f"{a} 和 {m} 没有互质，无法求模逆元")
    else:
        # 返回 x 的模 m 结果，即为 a 关于模 m 的逆元
        return x % m


# 主函数：根据给定的 p, q 和 e 计算 RSA 私钥 d
def rsa_private_key(p, q, e):
    # 计算 RSA 的 n 和 φ(n)
    n = p * q  # 公钥的模数 n = p * q
    phi_n = (p - 1) * (q - 1)  # 欧拉函数 φ(n) = (p-1)(q-1)

    # 计算 d = e^(-1) mod φ(n)，即 e 的模逆元
    d = mod_inverse(e, phi_n)

    # 返回计算得到的私钥 d
    return d


# 给定的 RSA 参数
p = int(input("请输入素数 p: "))  # 输入素数 p
q = int(input("请输入素数 q: "))  # 输入素数 q
e = int(input("请输入公钥指数 e: "))  # 输入公钥指数

# 调用 rsa_private_key 函数计算私钥 d
d = rsa_private_key(p, q, e)

# 输出计算得到的私钥 d
print(f"私钥 d 的值为: {d}")