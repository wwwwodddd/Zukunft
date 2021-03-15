def g(p):
	return (pow(2, pow(2, p, p - 1) + p - 2, p) * pow(2, p, p * p) % (p * p) // p)

def G(n):
	v = [0 for i in range(n + 1)]
	z = 0
	for i in range(2, n + 1):
		if v[i] == 0:
			if i % 2:
				z += g(i)
			for j in range(i, n + 1, i):
				v[j] = 1
	return z

print(G(10 ** 7))