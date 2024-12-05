n, m = map(int, input().split())
g = {}
for i in range(n):
	x, y, z, w = map(int, input().split())
	g[x, y, z] = w
for i in range(m):
	x, y, z = map(int, input().split())
	print(g.get((x, y, z), -1))
