w, n, k = map(int, input().split())
p = 10 ** 9 + 7
print(w * pow(2, (p - 2) * k, p) % p)