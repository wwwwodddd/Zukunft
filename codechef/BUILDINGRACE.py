for t in range(int(input())):
	a, b, x, y = map(int, input().split())
	if a * y < b * x:
		print('Chef')
	elif a * y > b * x:
		print('Chefina')
	else:
		print('Both')
