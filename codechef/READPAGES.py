for t in range(int(input())):
	n, x, y = map(int, input().split())
	print(['NO', 'YES'][n <= x * y])
