def bfs(x, y):
	s = a[x][y]
	a[x][y] = 0
	q = [(x, y)]
	while q:
		x, y = q.pop()
		for nx, ny in (x-1, y), (x+1, y), (x, y-1), (x, y+1):
			if 0 <= nx < n and 0 <= ny < m and a[nx][ny]:
				s += a[nx][ny]
				a[nx][ny] = 0
				q.append((nx, ny))
	return s

t = int(input())
for tt in range(t):
	n, m = map(int, input().split())
	a = []
	for i in range(n):
		a.append(list(map(int, input().split())))
	z = 0
	for i in range(n):
		for j in range(m):
			if a[i][j] > 0:
				z = max(z, bfs(i, j))
	print(z)