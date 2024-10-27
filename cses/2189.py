for t in range(int(input())):
	x1, y1, x2, y2, x3, y3 = map(int, input().split())
	x2 -= x1
	y2 -= y1
	x3 -= x1
	y3 -= y1
	if x2 * y3 - x3 * y2 > 0:
		print('LEFT')
	elif x2 * y3 - x3 * y2 < 0:
		print('RIGHT')
	else:
		print('TOUCH')
