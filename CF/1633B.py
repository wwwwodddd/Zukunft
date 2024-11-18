for t in range(int(input())):
	s = input()
	a = s.count('0')
	b = s.count('1')
	print(min(a, b) - (a == b))
