for t in range(int(input())):
	x, y = map(int, input().split())
	print(1500 - min(x * 2, y * 4) - x * 2 - y * 4)
