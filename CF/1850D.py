for t in range(int(input())):
	n, k = map(int, input().split())
	a = sorted(map(int, input().split()))
	z = 1
	c = 1
	for i in range(1, n):
		if a[i] - a[i - 1] > k:
			c = 1
		else:
			c += 1
		z = max(z, c)
	print(n - z)