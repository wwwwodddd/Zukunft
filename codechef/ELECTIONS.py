for t in range(int(input())):
	a = list(map(int, input().split()))
	if a[0] > 50:
		print('A')
	elif a[1] > 50:
		print('B')
	elif a[2] > 50:
		print('C')
	else:
		print('NOTA')
