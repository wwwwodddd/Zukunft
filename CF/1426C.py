for t in range(int(input())):
	n = int(input())
	i = int(n ** 0.5)
	print((n + i - 1) // i + i - 2)