for t in range(int(input())):
	n = int(input())
	s = input()
	if '1' in s:
		print(s.count('1') % 2)
	else:
		print(len(s))