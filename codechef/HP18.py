for t in range(int(input())):
	n, a, b = map(int, input().split())
	ac = 0
	bc = 0
	abc = 0
	for i in map(int, input().split()):
		if i % a == 0 and i % b == 0:
			abc += 1
		elif i % a == 0:
			ac += 1
		elif i % b == 0:
			bc += 1
	if abc > 0:
		ac += 1
	if ac > bc:
		print('BOB')
	else:
		print('ALICE')