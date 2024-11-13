for t in range(int(input())):
	s = input()
	i = 0
	z = 0
	while i + 1 < len(s):
		if s[i] != s[i + 1]:
			z += 1
			i += 2
		else:
			i += 1
	print(z)