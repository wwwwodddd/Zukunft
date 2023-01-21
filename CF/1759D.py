t = input()
for tt in range(int(t)):
	n, m = map(int, input().split())
	c2 = 0
	u = n
	while u % 2 == 0:
		u //= 2
		c2 += 1
	c5 = 0
	u = n
	while u % 5 == 0:
		u //= 5
		c5 += 1
	while True:
		if c2 > c5:
			if m < 5:
				n *= m
				break
			n *= 5
			m //= 5
			c5 += 1
		elif c2 < c5:
			if m < 2:
				n *= m
				break
			n *= 2
			m //= 2
			c2 += 1
		else:
			if m < 10:
				n *= m
				break
			n *= 10
			m //= 10
	print(n)