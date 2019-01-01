
for i in range(100, 333):
	s = '0' + str(i) + str(2 * i) + str(3 * i)
	if len(set(list(s))) == 10:
		print i, 2 * i, 3 * i
