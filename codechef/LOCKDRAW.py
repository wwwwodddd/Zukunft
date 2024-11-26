for t in range(int(input())):
	a, b, c = map(int, input().split())
	print(['NO', 'YES'][a + b + c == max(a, b, c) * 2])
