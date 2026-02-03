for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	g = {}
	for i in range(n):
		g[a[i]] = i + 1
	print(sum(g.values()))