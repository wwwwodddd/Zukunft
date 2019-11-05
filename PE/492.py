import sys

p = s = 10 ** 9
t = 10 ** 3
n = 10 ** 15
def F(x):
	return (6 * x * x + 10 * x + 3) % p

z = 0
for i in sys.stdin.readlines():
	p = eval(i)
	print p
	if p > s + t:
		break
	l = 0
	x = y = 1
	x = F(x)
	while x != y:
		x = F(F(x))
		y = F(y)
		l += 1

	c = 1
	y = F(y)
	while x != y:
		y = F(y)
		c += 1
	
	while l % c != n % c:
		y = F(y)
		l += 1

	print c
	z += y

print z