for t in range(int(input())):
	a, b, c = map(int, input().split())
	a += c % 2
	if a > b:
		print('First')
	else:
		print('Second')
