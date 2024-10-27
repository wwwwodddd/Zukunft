for t in range(int(input())):
	input()
	s = input()
	i = 0
	while 2 * i < len(s) and s[i] != s[len(s) - 1 - i]:
		i += 1
	print(len(s) - i - i)