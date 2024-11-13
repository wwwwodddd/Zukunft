for t in range(int(input())):
	a, b, c, d = map(int, input().split())
	print(['NO', 'YES'][a + c == b + d])