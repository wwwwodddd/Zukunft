f = [[0 for i in range(4000)] for j in range(30)]
g = [[0 for i in range(4000)] for j in range(30)]
f[0][0] = 1
g[0][0] = 0
for i in range(25):
	for j in range(i * 100 + 1):
		for k in range(10):
			f[i + 1][j + k * k] += f[i][j]
			g[i + 1][j + k * k] += g[i][j] * 10 + f[i][j] * k


s = 0
for i in range(60):
	s += g[20][i * i]
print s % 10 ** 9
