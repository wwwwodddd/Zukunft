for t in range(int(input())):
	n, k, m = map(int, input().split())
	print((n + k * m - 1) // (k * m))