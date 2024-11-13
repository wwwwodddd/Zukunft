for t in range(int(input())):
	x, y = map(int, input().split())
	print(['NO', 'YES'][5 * x >= y])
