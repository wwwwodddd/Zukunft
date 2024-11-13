for t in range(int(input())):
	n, k, x, y = map(int, input().split())
	print(k * x + (n - k) * min(x, y))
