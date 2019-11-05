p = 999999937
def C(n, m):
	if m < 0 or m > n:
		return 0
	if n < p and m < p:
		z = 1
		for i in range(m):
			z = z * (n - i) * pow(i + 1, p - 2, p) % p
		return z
	else:
		return C(n / p, m / p) * C(n % p, m % p) % p

def F(n, m, d):
	z = 0
	for i in range(m - d):
		z = (z + C(n - d, i) * pow(-1, i, p)) % p
#		print 'a', z, i
	z = z * C(n, d) % p
	return z

def FF(n, m, d):
	z = 0
	m -= d
	t = C((n - d) / p, m / p)
	nn = (n - d) % p
	mm = m % p
	cc = 1
	for i in range(m % p):
		z = (z + cc * pow(-1, i, p)) % p
		cc = cc * (nn - i) * pow(i + 1, p - 2, p) % p
#		print 'b', z, i
	z = z * t % p
	z = z * C(n, d) % p
	if m / p % 2 == 1:
		z = (-z) % p
	return z

for m in range(6, 100):
	a = F(10 ** 13, m, 4)
	b = FF(10 ** 13, m, 4)
	if a != b:
		print m, a, b
	assert a == b
print F(6, 3, 1), (-24) % p
print F(100, 10, 4), (-227197811615775 % p)
cao = FF(10 ** 13, 10 ** 12, 10 ** 4)
print cao % p, (-cao) % p