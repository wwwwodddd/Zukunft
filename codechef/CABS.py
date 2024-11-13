for t in range(int(input())):
	x, y = map(int, input().split())
	if x < y:
		print('FIRST')
	elif x > y:
		print('SECOND')
	else:
		print('ANY')
