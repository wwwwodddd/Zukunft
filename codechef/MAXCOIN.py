for t in range(int(input())):
	n, x = map(int, input().split())
	print(2 ** (n + 1) - 2 ** (n - x + 2) + 2)