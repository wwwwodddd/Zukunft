for t in range(int(input())):
	x, y, n, r = map(int, input().split())
	r -= n * x
	y -= x
	if r < 0:
		print(-1)
	else:
		m = min(n, r // y)
		print(n - m, m)