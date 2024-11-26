for t in range(int(input())):
	x, y, xr, yr, d = map(int, input().split())
	print(['NO', 'YES'][xr * d <= x and yr * d <= y])