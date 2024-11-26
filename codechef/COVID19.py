for t in range(int(input())):
	input()
	a = sorted(map(int, input().split()))
	x = len(a)
	y = 0
	c = 0
	for i in range(len(a)):
		if i > 0 and a[i] > a[i - 1] + 2:
			x = min(x, c)
			y = max(y, c)
			c = 0
		c += 1
	x = min(x, c)
	y = max(y, c)
	print(x, y)
