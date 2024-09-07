g = {'A': 0, 'B': 0}
while True:
	s = input()
	if s[0] == '1':
		o, x, n = s.split()
		g[x] = int(n)
	elif s[0] == '2':
		o, x = s.split()
		print(g[x])
	elif s[0] == '3':
		o, x, y = s.split()
		g[x] += g[y]
	elif s[0] == '4':
		o, x, y = s.split()
		g[x] *= g[y]
	elif s[0] == '5':
		o, x, y = s.split()
		g[x] -= g[y]
	elif s[0] == '6':
		o, x, y = s.split()
		d = 1
		if g[x] < 0:
			d *= -1
		if g[y] < 0:
			d *= -1
		g[x] = abs(g[x]) // abs(g[y]) * d
	elif s[0] == '7':
		break