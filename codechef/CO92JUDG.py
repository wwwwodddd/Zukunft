for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	x = sum(a) - max(a)
	y = sum(b) - max(b)
	if x < y:
		print('Alice')
	elif x > y:
		print('Bob')
	else:
		print('Draw')