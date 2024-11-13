for t in range(int(input())):
	x, y = map(int, input().split())
	print(['NO', 'YES'][x > 10 * y])
