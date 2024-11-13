for t in range(int(input())):
	x = int(input())
	if x < 3:
		print('LIGHT')
	elif x < 7:
		print('MODERATE')
	else:
		print('HEAVY')
