for t in range(int(input())):
	x, y, k = map(int, input().split())
	if (x + y) % (2 * k) < k:
		print('Chef')
	else:
		print('Paja')
