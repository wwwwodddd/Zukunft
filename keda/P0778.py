while True:
	n, *a = map(int, input().split())
	if n == 0:
		break
	s = []
	z = 0
	def push(x, y):
		global z
		w = 0
		while len(s) and s[-1][0] >= x:
			w += s[-1][1]
			z = max(z, s[-1][0] * w)
			s.pop()
		s.append((x, w + y))
	for i in a:
		push(i, 1)
	push(0, 0)
	print(z)
