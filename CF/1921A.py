for t in range(int(input())):
	a = sorted([list(map(int, input().split())) for i in range(4)])
	print((a[1][0] - a[0][0]) ** 2 + (a[1][1] - a[0][1]) ** 2)
