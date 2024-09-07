for t in range(int(input())):
	x, y, z, v = map(int, input().split())
	c = 0
	for i in range(1, x + 1):
		for j in range(1, y + 1):
			if v % (i * j) == 0 and v // i // j <= z:
				c = max(c, (x - i + 1) * (y - j + 1) * (z - v // i // j + 1))
	print(c)