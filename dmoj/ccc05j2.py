n = int(input())
m = int(input())
def F(n):
	c = 0
	for i in range(1, n + 1):
		if n % i == 0:
			c += 1
	return c == 4
s = sum(map(F, range(n, m + 1)))
print('The number of RSA numbers between %d and %d is %d' % (n, m, s))
