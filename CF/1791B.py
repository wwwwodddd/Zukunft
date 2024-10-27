for t in range(int(input())):
	n = int(input())
	s = input()
	x = 0
	y = 0
	z = 0
	for i in s:
		if i == 'L':
			x -= 1
		elif i == 'R':
			x += 1
		elif i == 'D':
			y -= 1
		elif i == 'U':
			y += 1
		if x == y == 1:
			z = 1
	if z:
		print('YES')
	else:
		print('NO')