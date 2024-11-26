for t in range(int(input())):
	x, y = map(int, input().split())
	for i in range(y):
		x += max(1000, x)
	print(x)