import math
p, q = 0, 1
for t in range(int(input())):
	x, y = map(int, input().split('/'))
	p, q = p * y + q * x, q * y
g = math.gcd(p, q)
p //= g
q //= g
if q == 1:
	print(p)
else:
	print('%d/%d' % (p, q))