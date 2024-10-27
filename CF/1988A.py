for t in range(int(input())):
	n, k = map(int, input().split())
	print((n - 1 + k - 2) // (k - 1))