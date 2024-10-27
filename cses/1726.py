t = int(input())
n = 8
p = [[1 for j in range(n)]for i in range(n)]
for i in range(n):
	for j in range(n):
		f = [[0 for l in range(n)]for k in range(n)]
		f[i][j] = 1
		for r in range(t):
			g = [[0 for l in range(n)]for k in range(n)]
			for k in range(n):
				for l in range(n):
					c = 0
					if k > 0:
						c += 1
					if k + 1 < n:
						c += 1
					if l > 0:
						c += 1
					if l + 1 < n:
						c += 1

					if k > 0:
						g[k - 1][l] += f[k][l] / c
					if k + 1 < n:
						g[k + 1][l] += f[k][l] / c
					if l > 0:
						g[k][l - 1] += f[k][l] / c
					if l + 1 < n:
						g[k][l + 1] += f[k][l] / c
			f = g
		for k in range(n):
			for l in range(n):
				p[k][l] *= (1 - f[k][l])
print('%.6f' % sum(sum(p[i]) for i in range(n)))