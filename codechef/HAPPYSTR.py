for t in range(int(input())):
	s = input()
	z = 0
	c = 0
	for i in s:
		if i in 'aeoiu':
			c += 1
		else:
			c = 0
		z = max(z, c)
	print(['Sad', 'Happy'][z > 2])
