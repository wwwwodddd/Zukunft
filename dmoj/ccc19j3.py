for t in range(int(input())):
	s = input()
	a = []
	c = 0
	l = ''
	for i in s:
		if i != l:
			if c > 0:
				a.append(c)
				a.append(l)
			l = i
			c = 0
		c += 1
	if c > 0:
		a.append(c)
		a.append(l)
	print(*a)