for t in range(int(input())):
	n, x, y = map(int, input().split())
	t = min(x, y // 3)
	n -= t
	x -= t
	if n <= x // 2:
		print('YES')
	else:
		print('NO')