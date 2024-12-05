s, k = input().split()
a = [[0 for j in range(10)]for i in range(10)]
for i in range(10):
	a[i][i] = 1
for i in range(int(k)):
	x, y = map(int, input().split())
	a[x][y] = 1
for k in range(10):
	for i in range(10):
		for j in range(10):
			if a[i][k] and a[k][j]:
				a[i][j] = 1
z = 1
for i in s:
	z = z * sum(a[int(i)])
print(z)