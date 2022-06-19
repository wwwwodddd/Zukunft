p = 998244353
n, k = map(int, input().split())
k -= (n + 1) // 2
z = 1
if k < 0:
	z = 0
for i in range(k):
	z = z * (n // 2 - i) * pow(i + 1, p - 2, p) % p
print(z)