for t in range(int(input())):
	n, m, k = map(int, input().split())
	print(*range(n, m, -1), *range(1, m + 1))
