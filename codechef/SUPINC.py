for t in range(int(input())):
	n, k, x = map(int, input().split())
	if x >= 2 ** (k - 1):
		print('Yes')
	else:
		print('No')