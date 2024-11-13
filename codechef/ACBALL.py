for t in range(int(input())):
	s = input()
	t = input()
	z = ''
	for i in range(len(s)):
		if s[i] != t[i] or s[i] == 'W':
			z += 'B'
		else:
			z += 'W'
	print(z)