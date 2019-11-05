def F(x):
	z = 0
	for j in range(100):
		if pow(x, j, 100) == j:
			z = j
			break
	else:
		return 0
	for i in range(2, 9):
		for j in range(10):
			if pow(x, z + j * 10 ** i, 10 ** (i + 1)) == (z + j * 10 ** i):
				z += j * 10 ** i
				break
		else:
			return 0
	return z

n = 10 ** 6
s = 0
for i in range(2, n + 1):
	if i % 10000 == 0:
		print i, s
	s += F(i)
print s
