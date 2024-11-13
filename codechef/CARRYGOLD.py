for t in range(int(input())):
	n, x, y = map(int, input().split())
	print(['NO', 'YES'][(n + 1) * y >= x])
