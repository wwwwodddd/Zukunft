n, q = map(int, input().split())
a = list(map(int, input().split()))
c = sum(a)
for i in range(q):
	x, y = map(int, input().split())
	if x == 1:
		y -= 1
		c -= a[y]
		a[y] ^= 1
		c += a[y]
	else:
		print(int(y <= c))