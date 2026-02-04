for t in range(int(input())):
	s = input()[::-1]
	t = ''
	for i in s:
		if i == 'w':
			t += 'w'
		elif i == 'p':
			t += 'q'
		elif i == 'q':
			t += 'p'
	print(t)
