for t in range(int(input())):
	s = input()
	z = 0
	for i in range(len(s)):
		if '-+'[i % 2] == s[i]:
			z += 1
	print(min(z, len(s) - z))