p = 10000019
def F(n):
	f = [0 for i in range(p)]
	i = 0
	f[0] = 1
	while i <= n - 1 - i:
		x = 10 ** i
		if i < n - 1 - i:
			x += 10 ** (n - 1 - i)
		x %= p
		g = [0 for u in range(p)]
		for j in range(p):
			for k in range(10):
				if i == 0 and k == 0:
					continue
				g[(j + k * x) % p] += f[j]
		f = g
		i += 1
	return f[0]

t = 32
z = 0
for i in range(1, t + 1):
	print i
	z += F(i)
print z