for t in range(int(input())):
	x, y = map(int, input().split())
	if x - 1 <= y <= x + 2:
		print('YES')
	else:
		print('NO')
