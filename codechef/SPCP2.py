for t in range(int(input())):
	x, n = map(int, input().split())
	print(max((n + 99) // 100 - x, 0))
