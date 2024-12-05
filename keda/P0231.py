n, m = map(int, input().split())
a = [list(map(int, input().split())) for i in range(n)]
b = [list(map(int, input().split())) for i in range(n)]
z = 0
for i in range(n):
	for j in range(m):
		z += (a[i][j] == b[i][j])
print('%.2f' % (z / n / m * 100))