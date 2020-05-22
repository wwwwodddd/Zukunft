n, a = map(int, raw_input().split())
f = [0 for i in range(6000)]
f[0] = 1
for x in map(int, raw_input().split()):
	x -= a
	g = f[::]
	for i in range(-3000, 3000):
		g[i + x] += f[i]
	f = g
print g[0] - 1