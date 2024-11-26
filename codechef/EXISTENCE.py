for t in range(int(input())):
	x, y = map(int, input().split())
	print(['NO', 'YES'][x ** 4 + 4 * y * y == 4 * x * x * y])