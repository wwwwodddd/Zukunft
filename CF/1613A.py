for t in range(int(input())):
	x1, p1 = map(int, input().split())
	x2, p2 = map(int, input().split())
	p = min(p1, p2)
	p1 -= p
	p2 -= p
	if p1 > 9:
		print('>')
	elif p2 > 9:
		print('<')
	else:
		x1 *= 10 ** p1
		x2 *= 10 ** p2
		if x1 > x2:
			print('>')
		elif x1 < x2:
			print('<')
		else:
			print('=')