for t in range(int(input())):
	s = input()
	z = 0
	for i in s:
		if i in 'B':
			z += 2
		elif i in 'ADOPQR':
			z += 1
	print(z)