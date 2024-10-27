for t in range(int(input())):
	n, k = map(int, input().split())
	s = 0
	if k * k < n:
		print('IMPOSSIBLE')
	else:
		a = []
		while s < n:
			a += range(min(n, s + k), s, -1)
			s += k
		print(*a)