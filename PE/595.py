import fractions
import itertools
import math
a = [0 for i in range(99)]
a[1] = fractions.Fraction(0, 1)
def C(n, m):
	return math.factorial(n) / math.factorial(m) / math.factorial(n - m)
for n in range(2, 53):
	f = [0 for i in range(n + 1)]
	for i in range(1, n + 1):
		f[i] = math.factorial(i) * C(n - 1, n - i)
	for i in range(1, n + 1):
		for j in range(0, i):
			f[i] -= C(n - j, n - i) * f[j]
	for i in range(1, n):
		a[n] += a[i] * f[i]
	a[n] = fractions.Fraction(a[n] + math.factorial(n), math.factorial(n) - f[n])
	print n, float(a[n] - 1)