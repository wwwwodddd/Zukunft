for t in range(int(input())):
	a, b, c = map(int, input().split())
	if b < a > c:
		print('Alice')
	elif a < b > c:
		print('Bob')
	else:
		print('Charlie')
