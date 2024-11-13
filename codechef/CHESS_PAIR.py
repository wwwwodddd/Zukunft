for t in range(int(input())):
	n, x = map(int, input().split())
	print(max(x - n, 0) * 2)
