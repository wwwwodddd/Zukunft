for t in range(int(input())):
	x, y, k = map(int, input().split())
	d = abs(x - y)
	e = abs(d - k)
	if e % 2:
		print(-1)
	else:
		print(e // 2)