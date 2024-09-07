for t in range(int(input())):
	n = int(input())
	if n <= 45 or n >= 315:
		print('N')
	elif n <= 135:
		print('E')
	elif n <= 225:
		print('S')
	else:
		print('W')