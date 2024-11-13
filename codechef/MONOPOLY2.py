for t in range(int(input())):
	a = list(map(int, input().split()))
	print(['NO', 'YES'][max(a) * 2 > sum(a)])