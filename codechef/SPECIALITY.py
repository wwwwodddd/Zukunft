for t in range(int(input())):
	x, y, z = map(int, input().split())
	if y < x > z:
		print('Setter')
	elif x < y > z:
		print('Tester')
	else:
		print('Editorialist')
