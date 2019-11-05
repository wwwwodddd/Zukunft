import fractions
lines = []
n = 5000
s = 290797
def next():
	global s
	s = s * s % 50515093
	return s % 500
for i in range(n):
	lines.append((next(), next(), next(), next()))

def xm(ax, ay, bx, by):
	return ax * by - ay * bx;

def fuck(a, b):
	if xm(a[0] - b[0], a[1] - b[1], b[2] - b[0], b[3] - b[1]) * xm(a[2] - b[0], a[3] - b[1], b[2] - b[0], b[3] - b[1]) >= 0:
		return None
	a, b = b, a
	if xm(a[0] - b[0], a[1] - b[1], b[2] - b[0], b[3] - b[1]) * xm(a[2] - b[0], a[3] - b[1], b[2] - b[0], b[3] - b[1]) >= 0:
		return None
	s0 = xm(a[0] - b[0], a[1] - b[1], b[2] - b[0], b[3] - b[1])
	s1 = -xm(a[2] - b[0], a[3] - b[1], b[2] - b[0], b[3] - b[1])
	x = fractions.Fraction(a[0] * s1 + a[2] * s0, s1 + s0)
	y = fractions.Fraction(a[1] * s1 + a[3] * s0, s1 + s0)
	return (x, y)


shabi = set([])
for i in range(n):
	if i % 100 == 0:
		print i
	for j in range(i):
		p = fuck(lines[i], lines[j])
		if p:
			shabi.add(p)

print len(shabi)