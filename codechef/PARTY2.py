for t in range(int(input())):
	n, x, k = map(int, input().split())
	print(['NO', 'YES'][n * x <= k])
