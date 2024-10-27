import sys
for t in range(int(input())):
	l = 2
	r = 999
	while l < r:
		lm = (2 * l + r) // 3
		rm = (l + 2 * r) // 3
		print('?', lm, rm)
		sys.stdout.flush()
		s = int(input())
		if lm * rm == s:
			l = rm + 1
		elif lm * (rm + 1) == s:
			l = lm + 1
			r = rm
		else:
			r = lm
	print('!', l)
	sys.stdout.flush()