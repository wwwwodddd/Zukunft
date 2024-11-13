for t in range(int(input())):
	n, m = map(int, input().split())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	c = [max(b[i] + 1 - a[i], 0) for i in range(n)]
	c.sort()
	d = 0
	for i in c:
		if m >= i:
			m -= i
			d += 1
	if d * 2 > n:
		print('YES')
	else:
		print('NO')
