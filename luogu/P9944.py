n = int(input())
z = 0
g = {}
def inc(x, y, d):
	global z
	if (x, y) not in g:
		g[(x, y)] = 0
	if g[(x, y)] == 13:
		z -= 1
	g[(x, y)] += d
	if g[(x, y)] == 13:
		z += 1
for i in range(n):
	x, y = map(int, input().split())
	inc(x, y, 10)
	inc(x + 1, y, 1)
	inc(x - 1, y, 1)
	inc(x, y + 1, 1)
	inc(x, y - 1, 1)
	print(z)
