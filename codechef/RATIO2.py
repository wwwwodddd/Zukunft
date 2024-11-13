for t in range(int(input())):
	x, y = map(int, input().split())
	print(max(min(x, y) - max(x, y) // 2, 0))