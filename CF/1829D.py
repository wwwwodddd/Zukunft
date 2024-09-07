def F(n, m):
	c = 0
	while m % n > 0:
		if n % 3:
			return False
		n //= 3
		c += 1
	m //= n
	if m & m - 1:
		return False
	return m <= 1 << c

t = int(input())
for tt in range(t):
	n, m = map(int, input().split())
	print(['NO', 'YES'][F(n, m)])
