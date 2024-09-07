st = sv = ed = int(input())
while True:
	o = input()
	if o == 'TAKE':
		ed += 1
	elif o == 'SERVE':
		sv += 1
	elif o == 'CLOSE':
		print(ed - st, ed - sv, (ed - 1) % 999 + 1)
		st = sv = ed = (ed - 1) % 999 + 1
	else:
		break
