for t in range(int(input())):
	n, k, s = map(int, input().split())
	print((s - n * n) // (k - 1))