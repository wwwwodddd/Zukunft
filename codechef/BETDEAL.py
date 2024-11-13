for t in range(int(input())):
	a, b = map(int, input().split())
	if 100 - a < 200 - 2 * b:
		print('FIRST')
	elif 100 - a > 200 - 2 * b:
		print('SECOND')
	else:
		print('BOTH')
