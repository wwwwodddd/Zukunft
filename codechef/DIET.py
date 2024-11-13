for t in range(int(input())):
	n, k = map(int, input().split())
	s = 0
	for i, x in enumerate(map(int, input().split())):
		s += x - k
		if s < 0:
			print('NO', i + 1)
			break
	else:
		print('YES')