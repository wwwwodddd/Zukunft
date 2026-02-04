for t in range(int(input())):
	a, s = map(int, input().split())
	if s >= a and ((s - a) & a) == a:
		print('Yes')
	else:
		print('No')