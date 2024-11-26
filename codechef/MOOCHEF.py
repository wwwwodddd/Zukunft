for t in range(int(input())):
	n, l, r = map(int, input().split())
	a = list(map(int, input().split()))
	x = y = s = 0
	for i in a:
		if l <= i <= r:
			s += 1
		else:
			s -= 1
		x = max(x, s)
		y = min(y, s)
	print(x, y)