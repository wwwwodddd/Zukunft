for t in range(int(input())):
	n = int(input())
	z = n * (n - 1) // 2
	g = {}
	for i in input().split():
		z -= g.get(i, 0)
		g[i] = g.get(i, 0) + 1
	print(z)
