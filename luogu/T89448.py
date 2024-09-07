n, l, m = map(int, raw_input().split())
p = 1000000007
c = [[0 for i in range(n + 1)] for j in range(n + 1)]
f = [[0 for i in range(n + 1)] for j in range(l + 1)]
for i in range(n + 1):
	c[i][0] = 1
	for j in range(1, i + 1):
		c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p
f[0][0] = 1
for i in range(l):
	for j in range(n + 1):
		for k in range(m + 1):
			if k <= j and m - k <= n - j:
				f[i + 1][j] = (f[i + 1][j] + f[i][j - k + m - k] * c[j][k] * c[n - j][m - k]) % p
A = raw_input()
B = raw_input()
t = 0
for i in range(n):
	if A[i] != B[i]:
		t += 1
print f[l][t]