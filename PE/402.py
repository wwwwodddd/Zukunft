from fractions import gcd
from sage.all import *

n = 1234567890123
mod = 10 ** 9

m = [[[0 for i in range(24)] for j in range(24)] for k in range(24)]
def M(a, b, c):
	g = 0
	for i in range(10):
		g = gcd(g, i ** 4 + a * i ** 3 + b * i ** 2 + c * i ** 1)
	return g
for a in range(24):
	for b in range(24):
		for c in range(24):
			m[a][b][c] = M(a, b, c)
def solve(n):
	t = [(n - i) // 24 + 1 for i in range(24)]
	t[0] -= 1
	ans = 0
	for a in range(24):
		for b in range(24):
			for c in range(24):
				ans += t[a] * t[b] * t[c] * m[a][b][c]
	return ans

print solve(10000)
def work(m):
	s = 0
	a = []
	for i in range(20):
		s += solve(fibonacci(m + i * 24))
		a.append(s)
	f = berlekamp_massey(a)
	R = PolynomialRing(Integers(mod), 'x'); x = R.gen()
	S = R.quotient(f, 'y');
	y = S.gen()
	re = y ** ((n - m) // 24)
	re = list(re)
	ans = 0
	for i in range(min(len(re), len(a))):
		ans = (ans + re[i] * a[i]) % mod
	return ans

ans = 0
for i in range(24):
	print i
	ans = (ans + work(i + 2)) % mod
print ans