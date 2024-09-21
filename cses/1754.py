for t in range(int(input())):
	x, y = map(int, input().split())
	if (x + y) % 3 == 0 and x * 2 >= y and y * 2 >= x:
		print('YES')
	else:
		print('NO')