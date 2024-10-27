for t in range(int(input())):
	n, k = map(int, input().split())
	if k >= n - 1:
		print(1)
	else:
		print(n)