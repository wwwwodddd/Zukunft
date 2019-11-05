def gcd(x, y):
	if y == 0:
		return x
	return gcd(y, x % y)

def lcm(x, y):
	return x / gcd(x, y) * y

def P(s, n):
	u = 1
	for i in range(1, s + 1):
		u = lcm(u, i)
	v = lcm(u, s + 1)
	n -= 2
	return n / u - n / v

print P(3, 14)
print P(6, 10 ** 6)

s = 0
for i in range(1, 32):
	s += P(i, 4 ** i)

print s