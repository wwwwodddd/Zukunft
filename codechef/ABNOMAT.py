for t in range(int(input())):
	input()
	s = set(input())
	t = set(input())
	if len(s | t) < 26:
		print('Yes')
	else:
		print('No')