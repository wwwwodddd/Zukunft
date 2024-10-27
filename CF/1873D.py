for t in range(int(input())):
	n, k = map(int, input().split())
	s = input()
	i = 0
	z = 0
	while i < n:
		if s[i] == 'B':
			i += k
			z += 1
		else:
			i += 1
	print(z)