for t in range(int(input())):
	n, c = map(float, input().split())
	print('%.2f' % (((n - 1) * c + (9 - n) * 4) / 8))