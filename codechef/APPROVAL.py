for t in range(int(input())):
	a = sorted(list(map(int, input().split())))
	s = sum(a)
	for i in range(len(a)):
		if s >= 35:
			print(i * 100)
			break
		s += 10 - a[i]
