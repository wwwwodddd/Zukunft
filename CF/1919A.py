for t in range(int(input())):
	a, b = map(int, input().split())
	if (a + b) % 2:
		print('Alice')
	else:
		print('Bob')
