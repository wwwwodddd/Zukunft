for t in range(int(input())):
	x, y = map(int, input().split())
	if x % 2 == 0 and x >= y % 2:
		print('YES')
	else:
		print('NO')