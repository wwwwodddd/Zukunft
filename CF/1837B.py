for t in range(int(input())):
	input()
	s = input()
	z = 1
	c = 1
	for i in range(1, len(s)):
		if s[i] == s[i - 1]:
			c += 1
			z = max(z, c)
		else:
			c = 1
	print(z + 1)