p = 1000000007
f = []
v = []
def C(n, m):
	if m < 0 or m > n:
		return 0
	return f[n] * v[m] % p * v[n - m] % p
def F(n):
	global f, v
	f = [0 for i in range(2 * n + 1)]
	v = [0 for i in range(2 * n + 1)]
	f[0] = v[0] = v[1] = 1
	for i in range(2, 2 * n + 1):
		v[i] = v[p % i] * (p - p // i) % p
	for i in range(1, 2 * n + 1):
		f[i] = f[i - 1] * i % p
		v[i] = v[i - 1] * v[i] % p
	x, y = 1, 3
	z = 0
	for i in range(n):
		z = (z + x * (C(2 * n - i - 3, n - 2) - C(2 * n - i - 3, n - 1))) % p
		x, y = y, (x + y) % p
	return z

print(F(8)) # 2663
print(F(20)) # 742296999
print(F(10**8))