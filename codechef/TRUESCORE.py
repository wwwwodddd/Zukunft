for t in range(int(input())):
	a, b = map(int, input().split())
	c, d = map(int, input().split())
	print(['IMPOSSIBLE', 'POSSIBLE'][a <= c and b <= d])