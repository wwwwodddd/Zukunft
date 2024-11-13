for t in range(int(input())):
	a, b, c, d = map(int, input().split())
	print(d - c + b - a + 2 - max(min(b, d) - max(a, c) + 1, 0))
