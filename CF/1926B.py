for t in range(int(input())):
	n = int(input())
	s = ''
	for i in range(n):
		s += input()
	if '010' in s:
		print('TRIANGLE')
	else:
		print('SQUARE')