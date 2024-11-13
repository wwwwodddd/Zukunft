for t in range(int(input())):
	n, x, p = map(int, input().split())
	if 4 * x - n >= p:
		print('PASS')
	else:
		print('FAIL')
