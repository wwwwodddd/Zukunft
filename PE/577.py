def F(n):
	n += 1
	ans = 0
	c = 0
	while True:
		n -= 3
		c += 1
		if n > 0:
			ans += n * (n + 1) / 2 * c
		else:
			break
	return ans


ans = 0
for i in xrange(3, 12345 + 1):
	ans += F(i)
print ans