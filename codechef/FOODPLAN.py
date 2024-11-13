for t in range(int(input())):
	n, m = map(int, input().split())
	if 9 * n < 10 * m:
		print('ONLINE')
	elif 9 * n > 10 * m:
		print('DINING')
	else:
		print('EITHER')
