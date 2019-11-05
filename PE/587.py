import math
def F(k):
	l = 0
	r = math.pi / 2
	for _ in range(100):
		m = (l + r) / 2
		x = 1 - math.cos(m)
		y = 1 - math.sin(m)
		if y * k < x:
			r = m
		else:
			l = m
	s = (4 - math.pi) / 4
	m = (l + r) / 2
	x = 1 - math.cos(m)
	y = 1 - math.sin(m)
	a = math.pi / 2 - m
	t = y / 2 - (a - math.sin(a)) / 2
	return t / s

for i in xrange(10000):
	if F(i) < 0.001:
		print i, F(i)
		break
