for t in range(int(input())):
	x, y = map(int, input().split(':'))
	if x == 0:
		print('12:%02d AM' % y)
	elif x < 12:
		print('%02d:%02d AM' % (x, y))
	elif x == 12:
		print('12:%02d PM' % y)
	else:
		print('%02d:%02d PM' % (x - 12, y))
