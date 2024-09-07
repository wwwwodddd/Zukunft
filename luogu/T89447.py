n, q = map(int, raw_input().split())
a = map(int, raw_input().split())
l = [-1 for i in range(n + 1)]
r = [-1 for i in range(n + 1)]
for i in range(n):
	r[i] = max(r[i - 1], l[a[i]])
	l[a[i]] = i
for i in range(q):
	x, y = map(int, raw_input().split())
	x -= 1
	y -= 1
	if r[y] < x:
		print 'Yes'
	else:
		print 'No'
