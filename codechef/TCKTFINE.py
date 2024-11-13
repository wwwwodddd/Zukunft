for t in range(int(input())):
	x, p, q = map(int, input().split())
	print(max(p - q, 0) * x)