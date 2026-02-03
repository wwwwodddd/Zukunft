for t in range(int(input())):
	s = input()
	a = []
	for i, c in enumerate(s):
		if c == '<':
			a.append(i)
		else:
			if len(a):
				a.pop()
			else:
				print(i)
				break
	else:
		if len(a):
			print(a[0])
		else:
			print(len(s))
