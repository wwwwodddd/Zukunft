for t in range(int(input())):
	z = 0
	for i in range(10):
		s = input()
		for j in range(10):
			if s[j] == 'X':
				z += min(i + 1, j + 1, 10 - i, 10 - j)
	print(z)