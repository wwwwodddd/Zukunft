for t in range(int(input())):
	n, a, b = map(int, input().split())
	s = map(int, input().split())
	c = 0
	for i in s:
		if c % 2 == 0:
			if i < a:
				c += 1
		else:
			if i > b:
				c += 1
	print((c + 1) // 2)