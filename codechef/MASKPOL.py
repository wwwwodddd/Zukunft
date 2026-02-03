for t in range(int(input())):
	x, y = map(int, input().split())
	print(min(y, x - y))