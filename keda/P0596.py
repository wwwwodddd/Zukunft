for i in range(int(input())):
	s = input()
	print(['no', 'yes'][s == s[::-1]])