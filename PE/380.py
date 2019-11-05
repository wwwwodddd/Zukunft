# http://oeis.org/A116469
from math import *
def C(n, m):
	s = 0
	for i in range(1, n):
		for j in range(1, m):
			s += log10(4*sin(i*pi/(2*n)) ** 2 + 4*sin(j*pi/(2*m)) ** 2)
	return pow(10, s - int(s)), int(s)
print '%.4fe%d' % C(9, 12)
print '%.4fe%d' % C(100, 500)