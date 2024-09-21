for t in range(int(input())):
	x, y = map(int, input().split())
	d = max(x, y)
	z = (d - 1) * (d - 1)
	if d & 1:
		if x == d:
			z += y
		else:
			z += d + d - x
	else:
		if y == d:
			z += x
		else:
			z += d + d - y
	print(z)
