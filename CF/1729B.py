for t in range(int(input())):
	n = int(input())
	s = input()
	z = ''
	i = n - 1
	while i >= 0:
		if s[i] == '0':
			z += chr(int(s[i - 2: i]) + 96)
			i -= 3
		else:
			z += chr(int(s[i]) + 96)
			i -= 1
	print(z[::-1])