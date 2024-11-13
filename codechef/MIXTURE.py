for t in range(int(input())):
	a, b = map(int, input().split())
	if a == 0:
		print('Liquid')
	elif b == 0:
		print('Solid')
	else:
		print('Solution')
