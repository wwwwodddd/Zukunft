from math import log
n = 10 ** 12 / 4
z = 0
while n > 0:
	t = n & -n
	z *= 2
	z += 3 ** int(log(t, 2))
	n -= t
print z
