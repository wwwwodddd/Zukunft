from math import *
n, m = map(int, input().split())
a, b = map(int, input().split())
x, y = n * b, m * a
x, y = x // gcd(x, y), y // gcd(x, y)
if a == 0 or b == 0:
	print(0)
else:
	print(x + y - 2)