#!/usr/local/bin/pypy
p = 10 ** 9 + 7
n = 10 ** 6
s = 0
for k in range(n + 1):
	if k % 1000 == 0:
		print k
	s = (s + (pow(1 - k * k, n + 1, p) - (1 - k * k)) * pow(-k * k, p - 2, p)) % p
print s