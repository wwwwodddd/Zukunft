n, m, l = map(int, input().split())
a = [list(map(int, input().split())) for i in range(n)]
for i in range(n):
	for j in range(m):
		a[i][j] *= l
for i in a:
	print(*i)