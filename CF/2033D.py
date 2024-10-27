for t in range(int(input())):
	n = int(input())
	g = {0}
	s = 0
	z = 0
	for i in map(int, input().split()):
		s += i
		if s in g:
			z += 1
			g = {s}
		else:
			g.add(s)
	print(z)