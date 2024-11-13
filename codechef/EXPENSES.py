for t in range(int(input())):
	n, x = map(int, input().split())
	print(1 << x - n)