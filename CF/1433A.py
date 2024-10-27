for t in range(int(input())):
	s = input()
	print((int(s[0]) - 1) * 10 + len(s) * (len(s) + 1) // 2)