for t in range(int(input())):
	x, y, z = map(int, input().split())
	if x >= y:
		print('PIZZA')
	elif x >= z:
		print('BURGER')
	else:
		print('NOTHING')