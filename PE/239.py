f = [0] * 110
g = [0] * 110
f[0] = 1
for i in range(1, 110):
	f[i] = f[i - 1] * i

def C(n, m):
	return f[n] / f[m] / f[n - m]

for i in range(25):
	g[i] = f[75 + i]
	for j in range(i):
		g[i] -= g[j] * C(i, j)
#print g[22]

print "0.%012d" % (g[22] * C(25, 22) * 10 ** 12 / f[100])
