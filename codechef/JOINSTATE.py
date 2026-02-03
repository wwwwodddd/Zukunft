for t in range(int(input())):
	n, m = map(int, input().split())
	z = 0
	s = 0
	for i in map(int, input().split()):
		s += i
		if s >= m:
			s = 0
			z += 1
	print(z)
