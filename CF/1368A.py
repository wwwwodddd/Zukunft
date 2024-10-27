for t in range(int(input())):
	a, b, n = map(int, input().split())
	c = 0
	while a <= n and b <= n:
		c += 1
		if a < b:
			a += b
		else:
			b += a
	print(c)