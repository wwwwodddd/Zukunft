for t in range(int(input())):
	x, y, k, n = map(int, input().split())
	z = 0
	for i in range(n):
		p, c = map(int, input().split())
		if c <= k:
			z = max(z, p)
	if z + y >= x:
		print('LuckyChef')
	else:
		print('UnluckyChef')
