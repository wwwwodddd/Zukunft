for t in range(int(input())):
	s = set()
	z = 0
	input()
	for i in map(int, input().split()):
		if i in s:
			s.discard(i)
		else:
			s.add(i)
		z = max(z, len(s))
	print(z)