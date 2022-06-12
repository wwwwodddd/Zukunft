for t in range(int(input())):
	n, x, y = map(int, input().split())
	print(4 * n - abs(n + 1 - x - y) - abs(x - y) - 4)