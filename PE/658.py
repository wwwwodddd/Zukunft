p = 1000000007
def F(x):
	if x == 0:
		return 1
	if x == 1:
		return n + 1
	return (pow(x, n + 1, p) - 1) * pow(x - 1, p - 2, p) % p

s = 0
m = 10 ** 7
n = 10 ** 12
m += 1
c = [0 for i in range(m + 1)]
o = [0 for i in range(m + 1)]
e = [0 for i in range(m + 1)]
c[0] = 1
for i in range(m):
	if i % 100000 == 0:
		print i
	c[i + 1] = c[i] * (m - i) * pow(i + 1, p - 2, p) % p
e[0] = 1
o[0] = 0
x = [0 for i in range(m - 1)]
inv2 = pow(2, p - 2, p)
for i in range(1, m + 1):
	if i % 100000 == 0:
		print i
	# c[i] = o[i] + e[i]
	if (m-i) % 2 == 1:
		# o[i] - e[i] = o[i - 1]
		o[i] = (c[i] + o[i - 1]) * inv2 % p
		e[i] = (c[i] - o[i - 1]) * inv2 % p
	else:
		# e[i] - o[i] = e[i - 1]
		e[i] = (c[i] + e[i - 1]) * inv2 % p
		o[i] = (c[i] - e[i - 1]) * inv2 % p
#	assert (o[i] + e[i]) == c[i]

m -= 1
def S(m, n):
	c = 1
	z = 0
	for i in range(1, m + 1):
		if i % 100000 == 0:
			print i
		x[i - 1] = (o[i] - (e[i] - 1)) % p
		z = (z + (o[i] - (e[i] - 1)) * F(i - 1)) % p
	return z

y = [0 for i in range(m)]
def I(m, n):
	c = 1
	z = 0
	for i in range(m):
		c = c * (m - i) * pow(i + 1, p - 2, p) % p
		if i % 2 == 0:
			y[m - i - 1] = (y[m - i - 1] + c) % p
			z = (z + c * F(m - i - 1)) % p
		else:
			y[m - i - 1] = (y[m - i - 1] - c) % p
			z = (z - c * F(m - i - 1)) % p
	return z

print S(m, n)
