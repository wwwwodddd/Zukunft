for t in range(int(input())):
	input()
	s = input() + '**'
	z = 0
	i = 0
	while i < len(s):
		if s[i] == '@':
			z += 1
		i += 1
		if s[i] == '*' and s[i + 1] == '*':
			break
	print(z)
