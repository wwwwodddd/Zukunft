for t in range(int(input())):
	m, n, k = map(int, input().split())
	print(['NO', 'YES'][m > n * k])