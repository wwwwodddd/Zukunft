f = [[0 for j in range(10)] for i in range(20)]
for i in range(10):
	f[1][i] = 1
for i in range(2, 20):
	for j in range(10):
		for k in range(10):
			if j != k:
				f[i][j] += f[i - 1][k]
def F(n):
	a = list(map(int, str(n)))
	d = len(a)
	z = n > 0
	for i in range(d):
		for j in range(1, 10):
			z += f[i][j]
	for i in range(d):
		for j in range(int(i == 0), a[i]):
			if i == 0 or j != a[i - 1]:
				z += f[d - i][j]
		if i > 0 and a[i] == a[i - 1]:
			break
	return z
x, y = map(int, input().split())
print(F(y + 1) - F(x))
