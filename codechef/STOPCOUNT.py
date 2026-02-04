for t in range(int(input())):
	n = int(input())
	s = input()
	c = 0
	z = 0
	for i in s:
		if i == '1':
			c += 1
		else:
			c -= 1
		if c > 0:
			z += 1
	print(z)