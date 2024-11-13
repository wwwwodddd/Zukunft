for t in range(int(input())):
	x1, y1, x2, y2 = map(int, input().split())
	print(min(x1 + y1, x2 + y2))
