n, m, k = map(int, input().split())
for i in range(n):
	s = input()
	z = list(s)
	d = k + 1
	for j in range(m):
		if s[j] == 'A':
			d = 0
		else:
			d += 1
			if s[j] == 'B':
				if d > k:
					z[j] = 'Y'
				else:
					z[j] = 'N'
	d = k + 1
	for j in range(m)[::-1]:
		if s[j] == 'B':
			d = 0
		else:
			d += 1
			if s[j] == 'A':
				if d > k:
					z[j] = 'Y'
				else:
					z[j] = 'N'
	print(''.join(z))