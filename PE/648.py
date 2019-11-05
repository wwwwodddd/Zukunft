from sage.all import *
def is_square(x):
	rt = int(x ** 0.5 + 0.5)
	if rt * rt == x:
		return rt
	return 0
A = Integers(10 ** 9)
R = PolynomialRing(A, 'x');
x = R.gen()
S = R.quotient(x ** (1000 + 1), 'y');
y = S.gen()
nn = 1000
f0 = 1
f1 = 0
f2 = 0
s = 0
for i in range(nn * nn - 2):
	rt = is_square(i)
	if rt > 0:
		s += f0 * (rt - 1)
	else:
		f1 += f0 * y
		f2 += f0 * (1 - y)
	f0, f1, f2 = f1, f2, 0
print sum(s.list()[:nn + 1])