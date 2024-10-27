for t in range(int(input())):
	c = 0
	s = input()
	t = '314159265358979323846264338327'
	for i in range(len(s)):
		if s[i] == t[i]:
			c += 1
		else:
			break
	print(c)