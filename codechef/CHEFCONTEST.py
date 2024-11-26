for t in range(int(input())):
	x, y, p, q = map(int, input().split())
	if x + 10 * p < y + 10 * q:
		print('Chef')
	elif x + 10 * p > y + 10 * q:
		print('Chefina')
	else:
		print('Draw')
