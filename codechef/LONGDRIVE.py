for t in range(int(input())):
	x, y = map(int, input().split())
	d = 100 - y
	print(((y - x) * 10 + d - 1) // d)
