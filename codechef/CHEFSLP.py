for t in range(int(input())):
	n, l, x = map(int, input().split())
	print(min(l, n - l) * x)
