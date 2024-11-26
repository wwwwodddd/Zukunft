for t in range(int(input())):
	x, a, b, c = map(int, input().split())
	a, b, c = sorted([a, b, c])
	print((x - 1) * a + b)
