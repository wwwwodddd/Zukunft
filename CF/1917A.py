for t in range(int(input())):
	input()
	s = 1
	a = list(map(int, input().split()))
	for i in range(len(a)):
		if a[i] < 0:
			s = -s
		elif a[i] == 0:
			s = 0
		if a[i]:
			p = i
	if s > 0:
		print(1)
		print(p + 1, 0)
	else:
		print(0)