n, m = map(int, input().split())
z = 0
for k in range(n):
	a = list(map(int, input().split()))
	f = [[0 for j in range(m)]for i in range(m)]
	for i in range(m):
		f[i][i] = a[i]
	for l in range(1, m):
		for i in range(m - l):
			j = i + l
			f[i][j] = max(a[i] + f[i+1][j] * 2, a[j] + f[i][j-1] * 2)
	z += f[0][m-1] * 2
print(z)