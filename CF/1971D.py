for t in range(int(input())):
	s = input()
	c01 = c10 = 0
	for i in range(1, len(s)):
		if s[i - 1] == '0' and s[i] == '1':
			c01 += 1
		if s[i - 1] == '1' and s[i] == '0':
			c10 += 1
	print(max(c01, 1) + c10)