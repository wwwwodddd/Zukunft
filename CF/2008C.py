for t in range(int(input())):
	l, r = map(int, input().split())
	r -= l
	L = 1
	R = 100000
	while L < R - 1:
		M = (L + R) // 2
		if M * (M - 1) // 2 <= r:
			L = M
		else:
			R = M
	print(L)