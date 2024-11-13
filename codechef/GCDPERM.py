for t in range(int(input())):
	n, m = map(int, input().split())
	print(*range(n // m, n // m * m + 1, n // m))