for tt in range(10):
	n, m, d = map(int, input().split())
	c = [0 for i in range(d + 1)]
	for x in map(int, input().split()):
		c[x] += 1
	l = n
	t = n
	z = 0
	for i in range(1, d + 1):
		if t == 0:
			t = l
			z += 1
		t -= 1
		l += c[i]
		t += c[i]
	print(z)