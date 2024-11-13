for t in range(int(input())):
	pa, pb, qa, qb = map(int, input().split())
	if max(pa, pb) < max(qa, qb):
		print('P')
	elif max(pa, pb) > max(qa, qb):
		print('Q')
	else:
		print('TIE')
