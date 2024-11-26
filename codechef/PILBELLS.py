for t in range(int(input())):
	n, x, k, p = map(int, input().split())
	print(min(x, k) * 10 + max(k - x, 0) * 5 + (k == n) * 20 + p)
