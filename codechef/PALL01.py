for t in range(int(input())):
	s = input()
	print(['loses', 'wins'][s == s[::-1]])