for t in range(int(input())):
	n, p, k = map(int, input().split())
	print((n // k + 1) * min(n % k, p % k) + (n // k) * max(p % k - n % k, 0) + p // k + 1)