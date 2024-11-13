for t in range(int(input())):
	a, b, c = map(int, input().split())
	print(['NO', 'YES'][max(a, b, c) <= (a + b + c + 1) // 2])