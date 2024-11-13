for t in range(int(input())):
	n = int(input())
	print(n, n - 2, *range(1, n - 3), n - 1)
