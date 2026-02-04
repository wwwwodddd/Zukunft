n, m, l = map(int, input().split())
a = [list(map(int, input().split())) for i in range(n)]
b = [list(map(int, input().split())) for i in range(m)]
c = [[0 for j in range(l)]for i in range(n)]
for i in range(n):
	for j in range(m):
		for k in range(l):
			c[i][k] += a[i][j] * b[j][k]
for i in c:
	print(*i)