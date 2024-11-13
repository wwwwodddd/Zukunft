for t in range(int(input())):
	s = input()
	t = input()
	print(''.join('BG'[x == y] for x, y in zip(s, t)))
