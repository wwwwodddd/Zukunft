for t in range(int(input())):
	x, y = map(int, input().split())
	if x * 107 >= y * 100:
		print('YES')
	else:
		print('NO')