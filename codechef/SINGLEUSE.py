for t in range(int(input())):
	n, x, y = map(int, input().split())
	print((n - y + x + x - 1) // x)