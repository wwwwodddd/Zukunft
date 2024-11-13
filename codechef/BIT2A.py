for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = sorted(a, reverse=True)
	c = 0
	g = {}
	for i in b:
		if i not in g:
			g[i] = c
		c += 1
	print(*[g[i] for i in a])