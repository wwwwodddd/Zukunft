for t in range(int(input())):
	s = input()
	p = int(input())
	a = sorted([(s[i], i) for i in range(len(s))])
	b = []
	i = 0
	while i < len(a):
		if p >= ord(a[i][0]) - 96:
			p -= ord(a[i][0]) - 96
			b.append((a[i][1], a[i][0]))
			i += 1
		else:
			break
	b.sort()
	print(''.join(y for x, y in b))