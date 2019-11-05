def F(x, n):
	i = x
	c = 0
	while True:
		c += 1
		if i < n:
			i *= 2
		else:
			i = (i - n) * 2 + 1
		if i == x:
			return c

def gcd(x, y):
	if y == 0:
		return x
	return gcd(y, x % y)

def lcm(x, y):
	return x / gcd(x, y) * y

def G(n):
	z = 1
	for i in range(2 * n):
		z = lcm(z, F(i, n))
	return z


def GG(n):
	if n == 1:
		return 1
	n = 2 * n - 1
	m = 1
	while True:
		if pow(2, m, n) == 1:
			return m
		m += 1


t = 255
for i in range(1, t + 1):
	if t % i == 0:
		print i, GG((i + 1) / 2), G((i + 1) / 2), 8
#for i in range(2, 100):
#	print G(i), GG(i)