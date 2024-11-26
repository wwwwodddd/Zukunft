for t in range(int(input())):
	x = int(input())
	s = input()
	if s.count('C') > s.count('N'):
		print(60 * x)
	elif s.count('C') < s.count('N'):
		print(40 * x)
	else:
		print(55 * x)
