for t in range(int(input())):
	n, k = map(int, input().split())
	print(['NO', 'YES'][k * (k + 1) // 2 + k - 1 <= n])
