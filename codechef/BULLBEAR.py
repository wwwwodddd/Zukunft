for t in range(int(input())):
	x, y = map(int, input().split())
	if x > y:
		print('LOSS')
	elif x < y:
		print('PROFIT')
	else:
		print('NEUTRAL')