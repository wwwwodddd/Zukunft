for t in range(int(input())):
	x, y, k = map(int, input().split())
	print(max((x + k - 1) // k * 2 - 1, (y + k - 1) // k * 2))