n = 10 ** 8
z = 0
def gcd(x, y):
	if y == 0:
		return x
	return gcd(y, x % y)
for i in range(1, n + 1):
	z += (n / i) * i
g = {}
def F(n):
	if n in g:
		return g[n]
	i = 1
	s = 0
	while i <= n:
		j = n / (n / i)
		s += (n / i) * (i + j) * (j - i + 1) / 2
		i = j + 1
	g[n] = s
	return g[n]
for i in range(1, n + 1):
	print i
	if i * i > n:
		break
	for j in range(1, n + 1):
		if i * i + j * j > n:
			break
		if gcd(i, j) == 1:
			s = n / (i * i + j * j)
			t = 0
			for k in range(1, s + 1):
				t += (s / k) * k
			z += 2 * t * i
print z
