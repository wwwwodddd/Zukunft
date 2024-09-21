n = int(input())
p = 1000000007
s = pow(2, n * n, p) + pow(2, (n * n + 3) // 4, p) * 2 + pow(2, (n * n + 1) // 2, p)
print(s * pow(4, p - 2, p) % p)