import sympy
n = 10 ** 6
z = 35440069342409237
for i in xrange(n + 1, 2 * n + 1):
	if i % 1000 == 0:
		print i
	z += max(sympy.factorint((i + 1)).keys() + sympy.factorint((i * i - i + 1)).keys()) - 1
print z