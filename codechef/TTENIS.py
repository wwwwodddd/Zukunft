for t in range(int(input())):
	s = input()
	if s.count('1') * 2 > len(s):
		print('WIN')
	else:
		print('LOSE')
