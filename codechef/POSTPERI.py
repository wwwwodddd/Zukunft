for t in range(int(input())):
	n, m, k = map(int, input().split())
	if 2 * (n + m) <= k:
		print(k - 2 * (n + m))
	else:
		print(max(k % 2, 4 - k))