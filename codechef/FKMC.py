for t in range(int(input())):
	input()
	s = input()
	z = c = 0
	for i in s:
		if i == '0':
			c += 1
		else:
			c = 0
		z = max(z, c)
	print(s.count('1') + z)