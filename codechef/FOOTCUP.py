for t in range(int(input())):
	x, y = map(int, input().split())
	if x == y and x > 0:
		print('YES')
	else:
		print('NO')