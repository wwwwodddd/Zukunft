for t in range(int(input())):
	x1, x2, x3, v1, v2 = map(int, input().split())
	x1 = x3 - x1
	x2 -= x3
	if x1 * v2 < x2 * v1:
		print('Chef')
	elif x1 * v2 > x2 * v1:
		print('Kefa')
	else:
		print('Draw')
