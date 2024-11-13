for t in range(int(input())):
	x, m, d = map(int, input().split())
	print(min(x * m, x + d))