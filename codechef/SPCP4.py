for t in range(int(input())):
	n, x, k = map(int, input().split())
	y = n - x
	print(abs(x % k - y % k))
