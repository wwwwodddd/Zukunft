for t in range(int(input())):
	p, m, v = map(int, input().split())
	print((m - p + 1) * v)