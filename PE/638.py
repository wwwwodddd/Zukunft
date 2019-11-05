p = 1000000007
n, m, l = 4, 4, 2

def C(n, m, l):
	if n == 0 or m == 0:
		return 1
	return (C(n - 1, m, l) * pow(l, m) + C(n, m - 1, l)) % p

def CC(n, m, l):
	f = [0 for i in range(n + 1)]
	f[0] = 1
	for i in range(m + 1):
		for j in range(n):
			f[j + 1] = (f[j + 1] + f[j] * pow(l, i)) % p
		print f
	return f[n]

def CCC(n, m, l):
	a = [0 for i in range(m)] + [1]
	for i in range(m):
		for j in range(1, i + 2):
			a[m - i - 1 + j] = a[m - i - 1 + j] * pow(l, j - 1, p) * pow((pow(l, j, p) - 1), p - 2, p) % p
			a[m - i - 1] = (a[m - i - 1] - a[m - i - 1 + j]) % p
	z = 0
	for j in range(m + 1):
		z += a[j] * pow(l, j * (n + 1), p) % p;
	return z % p


print CCC(n, m, l)
print CC(n, m, l)
assert(CCC(n, m, l) == CC(n, m, l))
#print C(n, m, l)
