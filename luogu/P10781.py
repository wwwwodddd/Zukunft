for t in range(int(input())):
	n, k = map(int, input().split())
	if n == 1:
		r = 1.0
	else:
		r = 1.5
	print('%.1f' % (k * r))