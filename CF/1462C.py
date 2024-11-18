for t in range(int(input())):
	x = int(input())
	s = ''
	for i in range(9, 0, -1):
		if x >= i:
			s = str(i) + s
			x -= i
		else:
			if x == 0:
				break
			s = str(x) + s
			x = 0
	if x:
		s = -1
	print(s)