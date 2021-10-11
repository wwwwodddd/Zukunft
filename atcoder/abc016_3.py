n, m = map(int, input().split())
a = [set([i])for i in range(n + 1)]
for i in range(m):
	x, y = map(int, input().split())
	a[x].add(y)
	a[y].add(x)
for i in range(1, n + 1):
	s = set()
	for j in a[i]:
		s |= a[j]
	print(len(s - a[i]))