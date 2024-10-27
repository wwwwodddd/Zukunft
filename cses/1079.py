p = 1000000007
m = 1000001
f = [0 for i in range(m)]
v = [0 for i in range(m)]
f[0] = 1
for i in range(1, m):
	f[i] = f[i - 1] * i % p
v[m - 1] = pow(f[m - 1], p - 2, p)
for i in range(m - 2, -1, -1):
	v[i] = v[i + 1] * (i + 1) % p
def C(n, m):
	return f[n] * v[m] % p * v[n - m] % p
for t in range(int(input())):
	a, b = map(int, input().split())
	print(C(a, b))