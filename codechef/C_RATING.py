for t in range(int(input())):
	x, y = map(int, input().split())
	print(max((y - x + 7) // 8, 0))
