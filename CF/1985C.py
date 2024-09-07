for t in range(int(input())):
	n = int(input())
	s = 0
	c = 0
	m = 0
	for i in map(int, input().split()):
		s += i
		m = max(m, i)
		if m * 2 == s:
			c += 1
	print(c)