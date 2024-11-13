for t in range(int(input())):
	n, k = map(int, input().split())
	print(['NO', 'YES'][n >= k * (k + 1) // 2])
