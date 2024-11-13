for t in range(int(input())):
	x, y = map(int, input().split())
	if x < y:
		print(y - x)
	else:
		print((x - y) // 2 + (x - y) % 2 * 2)