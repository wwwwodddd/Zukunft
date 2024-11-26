for t in range(int(input())):
	a, b, k = map(int, input().split())
	print((abs(a - b) + k - 1) // k)
