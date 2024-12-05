t = int(input())
for tt in range(t):
	n, m = map(int, input().split())
	s = input()
	g = -1e9
	h = -1e9
	z = ['.' for i in range(n)]
	for i in range(n):
		if s[i] == 'G':
			if g + m < i:
				if i + m < n:
					p = i + m
				else:
					p = n - 1
					while z[p] != '.':
						p -= 1
				z[p] = 'G'
				g = p
		elif s[i] == 'H':
			if h + m < i:
				if i + m < n:
					p = i + m
				else:
					p = n - 1
					while z[p] != '.':
						p -= 1
				z[p] = 'H'
				h = p
	z = ''.join(z)
	print(n - z.count('.'))
	print(z)