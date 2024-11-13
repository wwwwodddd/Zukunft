for t in range(int(input())):
	n, x = map(int, input().split())
	print(['NO', 'YES'][x % n == 0])
