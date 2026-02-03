for t in range(int(input())):
	n, x = map(int, input().split())
	p = l = r = 0
	for i in input():
		if i == 'L':
			p -= 1
		else:
			p += 1
		l = min(l, p)
		r = max(r, p)
	print(r - l + 1)
