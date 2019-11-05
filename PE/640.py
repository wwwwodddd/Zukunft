def F(n):
	f = [1e2 for i in range(2 ** (2 * n))]
	for r in range(2000):
		g = [1e30 for i in range(2 ** (2 * n))]
		f[0] = 0
		for i in range(2 ** (2 * n)):
			s = 0
			for j in range(1, n + 1):
				for k in range(1, n + 1):
					s += min(f[i ^ (1 << (j - 1))], f[i ^ (1 << (k - 1))], f[i ^ (1 << (j + k - 1))])
			s = s / n / n
			g[i] = s + 1
		f = g
		if r % 100 == 0:
			print f[2 ** (2 * n) - 1]
	return f[2 ** (2 * n) - 1]

print '%.6f' % F(6)