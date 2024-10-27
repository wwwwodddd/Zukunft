for t in range(int(input())):
	n, x = map(int, input().split())
	a = list(map(int, input().split()))
	L = 0
	R = 2147483647
	while L < R - 1:
		M = (L + R) // 2
		s = 0
		for i in a:
			s += max(0, M - i)
		if s <= x:
			L = M
		else:
			R = M
	print(L)