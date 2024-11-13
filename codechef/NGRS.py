for t in range(int(input())):
	x, y = map(int, input().split())
	if x < 50:
		print('Z')
	elif y < 50:
		print('F')
	else:
		print('A')
