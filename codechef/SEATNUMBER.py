for t in range(int(input())):
	n = int(input()) - 1
	s = []
	if n < 15:
		s.append('Lower')
	else:
		s.append('Upper')
	if n % 15 < 10:
		s.append('Double')
	else:
		s.append('Single')
	print(*s)