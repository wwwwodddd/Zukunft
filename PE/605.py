import fractions
def F(n, m):
	a = pow(2, n - m) * (n + (m - 1) * (pow(2, n) - 1))
	b = (pow(2, n) - 1) ** 2
	g = fractions.gcd(a, b)
	a /= g
	b /= g
	return a, b

#n = 6
#for i in range(n):
#	print F(n, i + 1)

p = 10 ** 8
def F(n, m):
	a = pow(2, n - m, p) * (n + (m - 1) * (pow(2, n, p) - 1)) % p
	b = (pow(2, n, p) - 1) ** 2 % p
	return a * b % p

print F(10 ** 8 + 7, 10 ** 4 + 7)