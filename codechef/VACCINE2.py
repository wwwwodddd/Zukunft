for t in range(int(input())):
	n, d = map(int, input().split())
	x = 0
	y = 0
	for i in map(int, input().split()):
		if 9 < i < 80:
			x += 1
		else:
			y += 1
	print((x + d - 1) // d + (y + d - 1) // d)