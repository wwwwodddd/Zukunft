for i in range(1, 10):
	a = []
	for j in range(1, i + 1):
		a.append('%d*%d=%-2d' % (j, i, i * j))
	print(*a)