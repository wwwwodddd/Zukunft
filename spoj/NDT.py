for t in range(int(input())):
	a, b, m = map(int, input().split())
	print((pow(a, b, m) - 1) % m + 1)