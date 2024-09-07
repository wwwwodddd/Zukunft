from math import gcd
x = int(input())
y = int(input())
g = gcd(x, y)
x //= g
y //= g
if x % y == 0:
	print(x // y)
elif x < y:
	print('%d/%d' % (x % y, y))
else:
	print(x // y, '%d/%d' % (x % y, y))