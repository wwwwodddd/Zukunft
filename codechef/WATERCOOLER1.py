for t in range(int(input())):
	x, y, m = map(int, input().split())
	print(['NO', 'YES'][x * m < y])