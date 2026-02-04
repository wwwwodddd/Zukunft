for t in range(int(input())):
	m, a, b, c = map(int, input().split())
	a = min(a, m)
	b = min(b, m)
	print(min(a + b + c, m * 2))
