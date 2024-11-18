for t in range(int(input())):
	b, p, f = map(int, input().split())
	h, c = map(int, input().split())
	b //= 2
	if h < c:
		h, c = c, h
		p, f = f, p
	t = min(b, p)
	b -= t
	p = t
	t = min(b, f)
	b -= t
	f = t
	print(p * h + f * c)