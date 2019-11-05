n = 10000019
c = 100
p = 10 ** 9
f = [0 for i in range(n)]
a = [2, 3, 5, 7]
b = [0, 0, 0, 0, 0]

for i in range(n):
	v = [0, 0, 0, 0, 0]
	for j in a:
		if i >= j:
			v[f[i - j]] = 1
	while v[f[i]] == 1:
		f[i] += 1

for i in range(5):
	b[i] = f.count(i)
f = [0 for i in range(8)]
f[0] = 1
for i in range(2 * c):
	g = [0 for i in range(8)]
	for j in range(8):
		for k in range(5):
			g[j ^ k] = (g[j ^ k]  +  f[j] * b[k]) % p
	f = g
print sum(g[1:]) % p