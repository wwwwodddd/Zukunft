f = [[0 for i in range(1024)] for j in range(20)]

for i in range(1, 10):
	f[1][1 << i] = 1
for i in range(1, 18):
	for j in range(1024):
		if f[i][j] == 0:
			continue
		for k in range(10):
			f[i + 1][j | (1 << k)] += f[i][j]

n = 18

g = [0 for i in range(1024)]
for i in range(n + 1):
	for j in range(1024):
		g[j] += f[i][j]

#for i in range(1024):
#	if g[i] > 0:
#		print bin(i), g[i]

print sum(g)
z = 0
for i in range(1024):
	for j in range(1024):
		if i & j:
			z += g[i] * g[j]

print z
print (z - 10 ** n + 1) / 2 % 1000267129
