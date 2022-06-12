for t in range(int(input())):
	x, y, z = map(int, input().split())
	if z % x == 0 and z % y == 0:
		print('ANY')
	elif z % x == 0:
		print('CHICKEN')
	elif z % y == 0:
		print('DUCK')
	else:
		print('NONE')