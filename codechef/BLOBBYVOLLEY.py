for t in range(int(input())):
	input()
	s = 'A' + input()
	x = 0
	y = 0
	for i in range(1, len(s)):
		if s[i] == s[i - 1]:
			if s[i] == 'A':
				x += 1
			else:
				y += 1
	print(x, y)
