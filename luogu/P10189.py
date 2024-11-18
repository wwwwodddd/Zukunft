n, q = map(int, input().split())
c = list(map(int, input().split()))
t = list(map(int, input().split()))
for i in range(n):
	c[i] -= t[i]
c.sort(reverse=True)
for i in range(q):
	v, s = map(int, input().split())
	if s < c[v - 1]:
		print('YES')
	else:
		print('NO')
