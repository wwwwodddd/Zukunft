for t in range(int(input())):
	a, b, c = map(int, input().split())
	if a > c < b:
		print('Alice')
	elif a > b < c:
		print('Bob')
	else:
		print('Draw')
