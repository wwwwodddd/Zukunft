for t in range(int(input())):
	x, y, z = map(int, input().split())
	if x + y > z:
		print('TRAIN')
	elif x + y < z:
		print('PLANEBUS')
	else:
		print('EQUAL')
