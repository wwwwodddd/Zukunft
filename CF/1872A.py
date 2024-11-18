for t in range(int(input())):
	a, b, c = map(int, input().split())
	c *= 2
	print((abs(a - b) + c - 1) // c)