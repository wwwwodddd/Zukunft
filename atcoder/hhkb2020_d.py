for t in range(int(input())):
	n, a, b = map(int, input().split())
	x = (n - a + 1) * (n - b + 1)
	y = (n + 1) * (a + b - 1) - b * (b - 1) - a * (a - 1) - a * b
	if a + b > n:
		print(0)
	else:
		print((x * x - y * y) % 1000000007)