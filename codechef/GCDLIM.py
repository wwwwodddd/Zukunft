mod = 998244353
n = 200001
d = [[] for i in range(n)]
for i in range(1, n):
	for j in range(i, n, i):
		d[j].append(i)

for t in range(int(input())):
	n = int(input())
	f = [0 for i in range(n + 1)]
	f[1] = 0
	for i in range(2, n + 1):
		g = [n // j for j in d[i]]
		for j in range(len(g))[::-1]:
			for k in range(j + 1, len(g)):
				if d[i][k] % d[i][j] == 0:
					g[j] -= g[k]
		for j in range(len(g) - 1):
			f[i] = (f[i] + f[d[i][j]] * g[j]) % mod
		f[i] = (f[i] * pow(n - (n // i), mod - 2, mod) + 1) % mod
	print(sum(f) * pow(n, mod - 2, mod) % mod)