for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	g = {}
	z = 0
	for i in range(n):
		a[i] -= i
		if a[i] not in g:
			g[a[i]] = 0
		z += g[a[i]]
		g[a[i]] += 1
	print(z)