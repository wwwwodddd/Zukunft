for t in range(int(input())):
	x1, x2, y1, y2, z1, z2 = map(int, input().split())
	if x1 <= x2 and y1 <= y2 and z1 >= z2:
		print('YES')
	else:
		print('NO')