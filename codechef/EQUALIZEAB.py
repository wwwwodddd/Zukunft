for t in range(int(input())):
	a, b, x = map(int, input().split())
	print(['NO', 'YES'][(a - b) % (2 * x) == 0])
