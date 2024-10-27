for t in range(int(input())):
	s = input()
	a = sorted(map(len, s.split('B')))
	print(sum(a[1:]))