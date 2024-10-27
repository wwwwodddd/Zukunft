n, m = map(int, input().split())
a = list(map(int, input().split()))
def zuo():
	g = {}
	for i in range(n):
		for j in range(i + 1, n):
			if m - a[i] - a[j] in g:
				print(g[m - a[i] - a[j]] + 1, i + 1, j + 1)
				return
		g[a[i]] = i
	print('IMPOSSIBLE')
zuo()