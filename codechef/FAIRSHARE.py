for t in range(int(input())):
	n, k = map(int, input().split())
	print(n // (k + 1) + n % (k + 1))
