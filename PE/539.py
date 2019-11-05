def F(x):
	b = 0
	while 2 << b <= x:
		b += 1
	x ^= 1 << b;
	for i in range(0, 70, 2):
		if x >> i & 1:
			x ^= 1 << i
	b = (b + 1) / 2
	return (4 ** b + 2) / 3 + x


def S(n):
	n += 1
	b = 0
	s = 0
	while 2 << b <= n:
		b += 1
	for i in range(b):
		s += (4 ** ((i + 1) / 2) + 2) / 3 * (2 ** i)
		for j in range(1, i, 2):
			s += 2 ** (i - 1) * (2 ** j)
	s += (n - 2 ** b) * ((4 ** ((b + 1) / 2) + 2) / 3)
	n -= 2 ** b
	for i in range(b)[::-1]:
		if n >> i & 1:
			if i % 2 == 0:
				n -= 2 ** i
				for j in range(1, i, 2):
					s += 2 ** (i - 1) * (2 ** j)
			else:
				n -= 2 ** i
				s += n * 2 ** i
				for j in range(1, i, 2):
					s += 2 ** (i - 1) * (2 ** j)
	return s
s = 0
n = 10**18

#for i in range(1, n + 1):
#	s += F(i)
#	print i, F(i), s
#	print i, F(i), s, S(i)
print s
print S(n) % 987654321