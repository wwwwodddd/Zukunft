for t in range(int(input())):
	a1, a2, b1, b2 = map(int, input().split())
	print(['NO', 'YES'][a2 + b2 - a1 - b1 > 0])
