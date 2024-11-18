for t in range(int(input())):
	input()
	s = input()
	c = 0
	for i in s:
		if i == '(':
			c += 1
		else:
			c = max(c - 1, 0)
	print(c)