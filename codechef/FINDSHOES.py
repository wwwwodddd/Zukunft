for t in range(int(input())):
	n, m = map(int, input().split())
	print(n + max(n - m, 0))