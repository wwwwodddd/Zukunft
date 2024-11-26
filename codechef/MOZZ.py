for t in range(int(input())):
	x, y, r = map(int, input().split())
	print((r // 30 + x + y - 1) // y)