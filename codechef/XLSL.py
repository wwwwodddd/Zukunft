for t in range(int(input())):
	x, y, z, a, b, c = map(int, input().split())
	r = min(c, z)
	z -= r
	y += z
	s = min(b, y)
	y -= s
	x += y
	t = min(a, x)
	print(r + s + t)