for t in range(int(input())):
	input()
	s = '0' + input() + '1'
	z = -1
	for i in range(1, len(s)):
		if s[i] == '1' and s[i - 1] == '0':
			z += 1
	print(z)
