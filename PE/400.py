n = 10000
f = [0 for i in range(2 * n)]
f[1] = 0
g2 = [0 for i in range(2 * n)]
f[2] = 1
g1 = [0 for i in range(2 * n)]
g1[0] = 1
p = 10 ** 18


for i in range(3, n + 1):
	print i
	f[i] = (f[i-1] + 1) ^ (f[i-2] + 1)
	g0 = [0 for j in range(2 * n)]
	for j in range(n):
		g0[(j + 1) ^ (f[i-2] + 1)] += g1[j]
	for j in range(n):
		g0[(j + 1) ^ (f[i-1] + 1)] += g2[j]
	g0[(f[i-1] + 1)] += 1
	g0[(f[i-2] + 1)] += 1
	for j in range(2 * n):
		g0[j] %= p
#	print i, f[i], g0
	g2 = g1
	g1 = g0

print f[n]
print g1[0]
