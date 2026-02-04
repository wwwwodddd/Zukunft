input()
a = input().split()
m, n = map(int, input().split())
f = [[0 for j in range(n+1)]for i in range(m+1)]
for s in a:
	x = s.count('0')
	y = s.count('1')
	for i in range(x,m+1)[::-1]:
		for j in range(y,n+1)[::-1]:
			f[i][j] = max(f[i][j], f[i-x][j-y] + 1)
print(f[m][n])