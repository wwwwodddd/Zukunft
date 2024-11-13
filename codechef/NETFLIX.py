for t in range(int(input())):
	a, b, c, x = map(int, input().split())
	print(['NO', 'YES'][a + b + c >= x + min(a, b, c)])