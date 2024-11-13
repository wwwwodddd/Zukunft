for t in range(int(input())):
	x, y, z = map(int, input().split())
	print(['NO', 'YES'][2 * z > x * y])