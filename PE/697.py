from math import *

def add(x, y):
	if x < y:
		x, y = y, x
	return x + log(1 + exp(y - x))

def gao1(lnc, n):
	c = exp(lnc)
	s = 1 / c
	r = 0
	for i in range(n):
		r += s
		# print(s)
		s = s * lnc / (i + 1)
	return r

def gao2(lnc, n):
	s = [0 for i in range(n)]
	s[n-1] = log(lnc) * (n - 1) - lnc
	for i in range(1, n):
		s[n-1] -= log(i)
	r = s[n-1]
	for i in range(1, n)[::-1]:
		s[i-1] = s[i] - log(lnc) + log(i)
		r = add(r, s[i-1])
	# for i in s:
	# 	print(exp(i))
	return r
	return exp(r)

lnc = log(2)
n = 3
print(gao1(lnc, n), gao2(lnc, n))

lnc = 46.27 / log10(e)
n = 100
print(gao1(lnc, n), gao2(lnc, n))

n = 10000000
L = 10002132
R = 10002233
for i in range(30):
	M = (L + R) / 2
	if gao2(M, n) < log(0.25):
		R = M
	else:
		L = M
	print(L, R, (L + R) / 2 * log10(e))

