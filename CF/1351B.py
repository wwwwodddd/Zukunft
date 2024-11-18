for t in range(int(input())):
	a1, b1 = map(int, input().split())
	a2, b2 = map(int, input().split())
	if b1 + b2 == a1 == a2:
		print('Yes')
	elif b1 + a2 == a1 == b2:
		print('Yes')
	elif a1 + b2 == b1 == a2:
		print('Yes')
	elif a1 + a2 == b1 == b2:
		print('Yes')
	else:
		print('No')
