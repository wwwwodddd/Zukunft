for t in range(int(input())):
	n, m, k = map(int, input().split())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	c = [0 for i in range(k)]
	for i in range(n):
		if a[i] <= k:
			c[a[i] - 1] |= 1
	for i in range(m):
		if b[i] <= k:
			c[b[i] - 1] |= 2
	if c.count(0) or c.count(1) + c.count(3) < k // 2 or c.count(2) + c.count(3) < k // 2:
		print('NO')
	else:
		print('YES')

