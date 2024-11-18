for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	s = a[0]
	for i in sorted(a[1:]):
		if s < i:
			s = (s + i + 1) // 2
	print(s)