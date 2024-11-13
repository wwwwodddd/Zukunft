for t in range(int(input())):
	n = int(input())
	if n % 14 == 0:
		print('Alice')
	elif n % 18 == 9:
		print('Bob')
	else:
		print('Charlie')