for t in range(int(input())):
	input()
	s = input()
	print(min(s.count('0') * 2 + 1, s.count('1') * 2 + 1, len(s)))
