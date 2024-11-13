for t in range(int(input())):
	x, y = map(int, input().split())
	print(abs((x - 1) // 10 - (y - 1) // 10))
