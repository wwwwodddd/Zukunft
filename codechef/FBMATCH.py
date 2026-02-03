for t in range(int(input())):
	input()
	s = input()
	if len(s) == len(set(s)):
		print('No')
	else:
		print('Yes')