for t in range(int(input())):
	s = input() + input() + input()
	print((3 - s.count('A')) * 'A' + (3 - s.count('B')) * 'B' + (3 - s.count('C')) * 'C')