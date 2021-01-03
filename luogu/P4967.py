n = eval(input())
p = 9223372036854775783
r2 = pow(2, (p + 1) // 4, p)
print(((pow(2 + r2, n + 1, p) + pow(2 - r2, n + 1, p)) * pow(4, p - 2, p) - pow(2, n, p)) % p)