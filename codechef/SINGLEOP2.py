for t in range(int(input())):
	n = int(input())
	s = input()
	p = s.find('1')
	q = s.find('1', p + 1)
	if q == -1:
		print(n)
	else:
		print(q - p)
