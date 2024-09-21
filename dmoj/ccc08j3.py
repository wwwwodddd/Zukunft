x = 0
y = 0
z = 0
o = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ -.\n'
for c in input() + '\n':
	p = o.index(c)
	nx = p // 6
	ny = p % 6
	z += abs(x - nx) + abs(y - ny)
	x = nx
	y = ny
print(z)
