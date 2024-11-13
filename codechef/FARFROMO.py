for t in range(int(input())):
	x1, y1, x2, y2 = map(int, input().split())
	d1 = x1 ** 2 + y1 ** 2
	d2 = x2 ** 2 + y2 ** 2
	if d1 < d2:
		print('BOB')
	elif d1 > d2:
		print('ALEX')
	else:
		print('EQUAL')