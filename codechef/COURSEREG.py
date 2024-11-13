for t in range(int(input())):
	n, m, k = map(int, input().split())
	print(['No', 'Yes'][n + k <= m])
