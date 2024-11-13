for t in range(int(input())):
	s = set(input().split())
	t = set(input().split())
	if len(s & t) >= 2:
		print('similar')
	else:
		print('dissimilar')