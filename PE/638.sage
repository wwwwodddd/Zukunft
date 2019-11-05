from sage.all import *
A = Integers(10 ** 9 + 7)
def F(n, m, k):
	k = A(k)
	R = PolynomialRing(A, 'x'); x = R.gen()
	S = R.quotient(x ** (n + 1), 'y'); y = S.gen()
	def F(l, r):
		if l == r:
			return (1 - k ** l * y)
		m = (l + r) / 2
		return F(l, m) * F(m + 1, r)
	t = F(0, m)
	return (1 / t).list()[n]

ans = A(0)
for i in range(1, 8):
	ans += F(10 ** i + i, 10 ** i + i, i)
	print ans