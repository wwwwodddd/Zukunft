n, m = map(int, input().split())
a = [list(map(int, input().split())) for i in range(n)]
b = [list(map(int, input().split())) for i in range(n)]
c = [list(map(int, input().split())) for i in range(n)]
for i in range(n):
	for j in range(m):
		a[i][j] += c[i][j] - b[i][j]
for i in a:
	print(*i)