n, m = map(int, input().split())
a = [list(map(int, input().split())) for i in range(n)]
f = [[0 for j in range(m)]for i in range(n)]
for i in range(n):
	for j in range(m):
		f[i][j] = 10**9
		if i == 0 and j == 0:
			f[i][j] = 0
		if i > 0:
			f[i][j] = min(f[i][j], f[i - 1][j])
		if j > 0:
			f[i][j] = min(f[i][j], f[i][j - 1])
		f[i][j] += a[i][j]
print(f[n-1][m-1])