for t in range(int(input())):
	s = input()
	c0 = s.count('0')
	c1 = s.count('1')
	z = 0
	for i in s:
		if i == '0':
			if c1 > 0:
				c1 -= 1
				z += 1
			else:
				break
		else:
			if c0 > 0:
				c0 -= 1
				z += 1
			else:
				break
	print(len(s) - z)
