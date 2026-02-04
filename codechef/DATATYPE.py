for t in range(int(input())):
	n, x = map(int, input().split())
	print(x % (n + 1))