for t in range(int(input())):
	x, y = map(int, input().split())
	if x < y * 2:
		print((x + y) // 3 * 2)
	else:
		print(y + (x + y) // 3)