for _ in range(1, input() + 1):
	cnt = 0
	a = map(int, raw_input().split())
	for i in range(3 ** 6):
		b = [0, 0, 0, 0]
		for j in range(4):
			for k in range(j):
				u = i % 3
				if u == 0:
					b[j] += 3
				if u == 1:
					b[j] += 1
					b[k] += 1
				if u == 2:
					b[k] += 3
				i /= 3
		if a == b:
			cnt += 1
	print 'Case #%d:' % _, ['Wrong Scoreboard', 'Yes', 'No'][min(cnt, 2)]