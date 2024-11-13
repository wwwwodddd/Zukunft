for t in range(int(input())):
	n, x = map(int, input().split())
	print(['NO', 'YES'][9999 < n * x < 100000])