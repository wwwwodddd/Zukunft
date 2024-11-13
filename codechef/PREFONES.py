for t in range(int(input())):
	input()
	s = input()
	a = list(map(len, s.split('0'))) + [0]
	print(a[0] + max(a[1:]))
