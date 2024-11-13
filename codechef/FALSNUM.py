for t in range(int(input())):
	s = input()
	print(min('1' + s, s[0] + '0' + s[1:]))
