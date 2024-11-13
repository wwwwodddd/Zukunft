for t in range(int(input())):
	a, b = map(int, input().split())
	print(['NO', 'YES'][a > b])
