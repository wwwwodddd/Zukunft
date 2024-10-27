import collections
for t in range(int(input())):
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	l = a[:n]
	c = collections.Counter(l)
	l.sort(key=lambda x:(-c[x], x))
	r = a[n:]
	c = collections.Counter(r)
	r.sort(key=lambda x:(-c[x], x))
	print(*l[:2 * k])
	print(*r[:2 * k])
