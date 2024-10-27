for t in range(int(input())):
	n, k = map(int, input().split())
	l = 0
	r = n - 1
	while l < r - 1:
		m = (l + r) // 2
		if (k + k + m) * (m + 1) * 2 <= (k + k + n - 1) * n:
			l = m
		else:
			r = m
	x = abs((k + k + n - 1) * n // 2 - (k + k + l) * (l + 1))
	y = abs((k + k + n - 1) * n // 2 - (k + k + r) * (r + 1))
	print(min(x, y))