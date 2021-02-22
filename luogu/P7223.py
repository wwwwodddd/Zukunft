mod = 998244353
n, p = map(int, input().split())
z = 1
for x in map(int, input().split()):
	z = z * (pow(p, x, mod) + 1) % mod
print(z)