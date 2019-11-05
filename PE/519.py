from collections import defaultdict

n = 20000
p = 10 ** 9
f = [defaultdict(int) for i in range(n + 1)]


f[1][1] = 3
for i in range(1, n):
	print i
	for j in f[i]:
		for k in range(1, min(j + 1, n - i) + 1):
			if j == 1:
				f[i + k][k] = (f[i + k][k] + 2 * f[i][j]) % p
			elif k == 1:
				f[i + k][k] = (f[i + k][k] + 2 * f[i][j]) % p
			else:
				f[i + k][k] = (f[i + k][k] + f[i][j]) % p
print sum(f[n].values()) % p