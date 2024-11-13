for t in range(int(input())):
	n, m = map(int, input().split())
	print(['No', 'Yes'][n % (2 * m) == 0])
