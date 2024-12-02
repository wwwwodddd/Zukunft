m, n = map(int, input().split())
s = input().split()
a = [[-1 for i in range(n)] for j in range(n)]
for i in range(m):
	b = input().split()
	c = []
	d = []
	for j in range(n):
		if j == 0:
			d = [b[j]]
		elif b[j - 1] > b[j]:
			c.append(d)
			d = [b[j]]
		else:
			d.append(b[j])
	c.append(d)
	for l in range(1, len(c)):
		for j in c[l - 1]:
			for k in c[l]:
				a[s.index(j)][s.index(k)] = 0
				a[s.index(k)][s.index(j)] = 1

for k in range(n):
	for i in range(n):
		for j in range(n):
			if a[i][k] == 0 and a[k][j] == 0:
				a[i][j] = 0
			if a[i][k] == 1 and a[k][j] == 1:
				a[i][j] = 1
for i in range(n):
	s = ''
	for j in range(n):
		if i == j:
			s += 'B'
		elif a[i][j] == 0:
			s += '0'
		elif a[i][j] == 1:
			s += '1'
		else:
			s += '?'
	print(s)