n, m = map(int, input().split())
a = [input() for i in range(n)]
g = set()
di = [0, 0, 1, -1]
dj = [1, -1, 0, 0]
z = 0
def valid(i, j):
	return i >= 0 and j >= 0 and i < n and j < m
for i in range(n):
	for j in range(m):
		if a[i][j] == 'G':
			c = 0
			b = []
			for k in range(4):
				ni = i + di[k]
				nj = j + dj[k]
				if valid(ni, nj) and a[ni][nj] == 'C':
					c += 1
					b.append((ni, nj))
			if c > 2:
				z += 1
			elif c == 2:
				b = tuple(sorted(b))
				b = b[0][0] * 1000000000000 + b[0][1] * 100000000 + b[1][0] * 10000 + b[1][1]
				if b not in g:
					z += 1
					g.add(b)
print(z)