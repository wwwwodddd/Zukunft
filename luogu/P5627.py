n = int(input())
p = 1000000007
print((n + (1 + pow(2, n - 1, p)) * (pow(2, n, p) - n - 1)) % p)