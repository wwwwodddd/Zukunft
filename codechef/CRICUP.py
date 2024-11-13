for t in range(int(input())):
	x, y, d = map(int, input().split())
	print(['NO', 'YES'][abs(x - y) <= d])