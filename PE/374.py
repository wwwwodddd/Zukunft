def F(n):
	i = 0
	while (i + 3) * i / 2 <= n:
		i += 1
	i -= 1

	t = n - (i + 3) * i / 2
	a = []
	if n == 1:
		a = [1]
	elif t == i + 1:
		a = range(3, 2 + i) + [3 + i]
	else:
		a = range(2, 2 + i - t) + range(3 + i - t, 3 + i)
	s = 1
	for i in a:
		s *= i
#	return len(a), a
	return s * len(a)

p = 982451653

def S(n):
	z = 0
	for i in range(1, n + 1):
		z += F(i)
	return z % p

def SS(n):
	z = 1
	s = 2
	m = 2 * 3
	v = (pow(2, p - 2, p) + pow(3, p - 2, p)) % p
	i = 2
	while s + i <= n:
		z = (z + m * (v + pow(2 * (i + 1), p - 2, p) * (i + 2)) * (i - 1)) % p
		m = (m * (i + 2)) % p
		v = (v + pow(i + 2, p - 2, p)) % p
		i += 1
		s += i
	l = n - s + 1
	for u in range(l):
		z = (z + m * pow(1 + i - u, p - 2, p) * (i - 1)) % p
	return z % p
#for i in range(1, 40):
#	print i, F(i)

#print S(12313)
print SS(10 ** 14)



