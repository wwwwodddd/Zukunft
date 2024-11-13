for t in range(int(input())):
	n, m = map(int, input().split())
	print(['NO', 'YES'][n > m])
