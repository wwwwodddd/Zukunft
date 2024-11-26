for t in range(int(input())):
	x = int(input())
	if x > 65:
		print('Overload')
	elif x < 35:
		print('Underload')
	else:
		print('Normal')