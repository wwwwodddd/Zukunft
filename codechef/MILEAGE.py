for t in range(int(input())):
	n, x, y, a, b = map(int, input().split())
	if x * b < y * a:
		print('PETROL')
	elif x * b > y * a:
		print('DIESEL')
	else:
		print('ANY')
