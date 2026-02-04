for t in range(int(input())):
	n = int(input())
	s = input()
	z = ''
	c = ''
	for i in s:
		if c == '':
			c = i
			z += c
		elif c == i:
			c = ''
	print(z)