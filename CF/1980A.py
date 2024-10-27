for t in range(int(input())):
	n, m = map(int, input().split())
	s = input()
	z = 0
	for i in 'ABCDEFG':
		z += max(m - s.count(i), 0)
	print(z)