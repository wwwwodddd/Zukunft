a = [list(map(int, input().split())) for i in range(3)]
for i in range(3):
	s = ''
	for j in range(3):
		c = 1
		for x, y in (i, j), (i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1):
			if 0 <= x < 3 and 0 <= y < 3:
				c = (c + a[x][y]) % 2
		s += str(c)
	print(s)