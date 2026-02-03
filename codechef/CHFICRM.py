for t in range(int(input())):
	input()
	x = 0
	y = 0
	for i in map(int, input().split()):
		if i == 5:
			x += 1
		elif i == 10:
			if x >= 1:
				x -= 1
				y += 1
			else:
				print('NO')
				break
		else:
			if y >= 1:
				y -= 1
			elif x >= 2:
				x -= 2
			else:
				print('NO')
				break
	else:
		print('YES')