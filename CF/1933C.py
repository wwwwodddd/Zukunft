for t in range(int(input())):
	a, b, l = map(int, input().split())
	s = set()
	while True:
		t = l
		while True:
			s.add(t)
			if t % b == 0:
				t //= b
			else:
				break
		if l % a == 0:
			l //= a
		else:
			break
	print(len(s))