n, m = map(int, input().split())
m += 1
s = input()
f = [[0 for j in range(n + 1)]for i in range(m + 1)]
f[0][0] = 1
for i in range(1, m + 1):
	for j in range(i, n + 1):
		for k in range(j):
			f[i][j] = max(f[i][j], f[i-1][k] * int(s[k:j]))
print(f[m][n])