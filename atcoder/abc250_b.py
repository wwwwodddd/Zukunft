n, a, b = map(int, input().split())
for i in range(n):
	for i1 in range(a):
		s = ''
		for j in range(n):
			for j1 in range(b):
				if (i + j) % 2 == 0:
					s += '.'
				else:
					s += '#'
		print(s)