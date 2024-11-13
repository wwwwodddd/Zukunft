for t in range(int(input())):
	n, x = map(int, input().split())
	print((n + x % 2) // 2 - 1)