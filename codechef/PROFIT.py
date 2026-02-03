for t in range(int(input())):
	n, x = map(int, input().split())
	n = max(n - x, 0)
	print(n * (n + 1) // 2)