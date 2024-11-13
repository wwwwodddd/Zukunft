for t in range(int(input())):
	x, h = map(int, input().split())
	if x * 5 < h * 2:
		print((h - x // 2 * 5 + x - 1) // x + 5)
	else:
		print((h * 2 + x - 1) // x)