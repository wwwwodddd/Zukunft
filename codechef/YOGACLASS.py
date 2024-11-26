for t in range(int(input())):
	n, x, y = map(int, input().split())
	y = max(y, 2 * x)
	print(n // 2 * y + n % 2 * x)