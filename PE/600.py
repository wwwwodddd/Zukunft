def A(x, y, d):
	if y < 0:
		y = -y
	d = d - x - y
	d = d - x - y
	d = max(d, 0)
	z = d * (d - 1) / 2
	d = max(d - (x - 1), 0)
	z -= d * (d - 1)
	d = max(d - (x - 1), 0)
	z += d * (d - 1) / 2
	return z

def B(x, y, d):
	if y < 0:
		y = -y
	d = d - x - y
	d = d - x - y
	d = max(d, 0)
	z = min(x - 1, d / 2)
	return z

n = 55106
L = n / 2

def F(n):
	z = 0
	for i in range(1, L):
		for j in range(-L, L):
			z += A(i, j, n)
	return z

def G(n):
	z = 0
	for i in range(1, L):
		for j in range(-L, L):
			z += B(i, j, n)
	return z


def H(n):
	n /= 3
	return n * (n - 1) / 2

def I(n):
	n /= 6
	return n

def J(n):
	z = 0
	for i in range(1, L):
		z += B(i, 0, n)
	return z

def K(n):
	z = 0
	for i in range(1, L):
		for j in range(1, L):
			z += max(n - i - i - j - j - abs(i - j), 0) / 2
	return z
#print F(n), G(n), H(n), I(n)
z = F(n) + G(n) + 2 * H(n) + 2 * I(n) + 3 * J(n) + 3 * K(n)
print z, z / 12, z % 12