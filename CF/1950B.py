for t in range(int(input())):
	n = int(input())
	for i in range(2 * n):
		s = ''
		for j in range(2 * n):
			if (i // 2 + j // 2) & 1:
				s += '.'
			else:
				s += '#'
		print(s)