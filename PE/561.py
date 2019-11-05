def E(m, n):
	s = ((n + 1) * (n + 2) / 2) ** m - (n + 1) ** m
	z = 0
	while s % 2 == 0:
		z += 1
		s /= 2
	return z
	# =.=
def F(m, n):
	if n % 4 == 3:
		n = (n + 1) / 4
		c = 1
		while n % 2 == 0:
			c += 1
			n /= 2
		return c * m
	if n % 4 == 0:
		if m % 2 == 1:
			n = n / 4
			c = 1
			while n % 2 == 0:
				c += 1
				n /= 2
			return c
		else:
			n = (n + 4) / 8
			c = 2
			while m % 2 == 0:
				c += 1
				m /= 2
			while n % 2 == 0:
				c += 1
				n /= 2
			return c
	return 0

def Q(n):
	z = 0
	for i in range(1, n + 1):
		t = F(904961, i)
		z += t
#		print i, t
	return z

def B(x):
	z = 1
	while x % 2 == 0:
		z += 1
		x /= 2
	return z

def P(n):
	n /= 4
	z = 0
	for i in range(1, n + 1):
		z += B(i)
	return z * 904962

def R(n):
	n /= 4
	n += 1
	z = 0
	c = -1
	for i in range(64)[::-1]:
		if n >> i & 1:
			for j in range(i):
				z += (j + 1) * 2 ** (i - j - 1)
			if c == -1:
				c = 0
			else:
				z += c + i + 2
				c = 0
		else:
			if c != -1:
				c += 1
	return z * 904962

n = 10 ** 12
print R(n)
#print Q(n), P(n), R(n)