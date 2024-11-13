for t in range(int(input())):
	a, b, c = map(int, input().split())
	if a + b + c >= 100 and min(a, b, c) >= 10:
		print('PASS')
	else:
		print('FAIL')
