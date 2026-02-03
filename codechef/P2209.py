for t in range(int(input())):
	x, y = map(int, input().split())
	if x % 2 == 0 or y // x % 2 == 0:
		print('YES')
	else:
		print('NO')