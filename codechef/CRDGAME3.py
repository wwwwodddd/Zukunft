for t in range(int(input())):
	x, y = map(int, input().split())
	x = (x + 8) // 9
	y = (y + 8) // 9
	if x < y:
		print(0, x)
	else:
		print(1, y)