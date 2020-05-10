from fractions import *
for _ in range(1, input() + 1):
	n = input()
	a = []
	for i in range(n):
		x, y = map(Fraction, raw_input().split(':'))
		a.append(x / (x + y))
	a = sorted(a)
	s = 0
	for i in range(n):
		s += a[i]
		if s >= 1:
			print 'Case #%d:' % _, i
			break
	else:
		print 'Case #%d:' % _, n