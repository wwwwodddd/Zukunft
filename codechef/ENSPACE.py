for t in range(int(input())):
	n, x, y = map(int, input().split())
	if x + 2 * y <= n:
		print('YES')
	else:
		print('NO')
