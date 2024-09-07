for t in range(int(input())):
	n = int(input())
	if 80 <= n <= 100:
		print('A')
	elif 70 <= n <= 79:
		print('B')
	elif 60 <= n <= 69:
		print('C')
	elif 50 <= n <= 59:
		print('D')
	elif 0 <= n <= 49:
		print('F')
	else:
		print('X')