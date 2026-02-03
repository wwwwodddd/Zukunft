for t in range(int(input())):
	a, b = map(int, input().split())
	if a * 9 < b * 4:
		print('Small')
	elif a * 9 > b * 4:
		print('Large')
	else:
		print('Equal')