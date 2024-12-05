from math import gcd
a, b, c = map(int, input().split())
if c % gcd(a, b) == 0:
	print('true')
else:
	print('false')