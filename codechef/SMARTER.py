for t in range(int(input())):
	l, x, y = map(int, input().split())
	print(max((l + x - 1) // x - 1 - (l + y - 1) // y, -1))
