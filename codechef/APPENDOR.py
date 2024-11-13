for t in range(int(input())):
	n, y = map(int, input().split())
	s = 0
	for i in map(int, input().split()):
		s |= i
	if (s | y) == y:
		print(y - s)
	else:
		print(-1)