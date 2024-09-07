n, m = map(int, raw_input().split())
a = [0 for i in range(n + 1)]
for i in range(m):
	x, y, z = map(int, raw_input().split())
	if x < y:
		a[x] += z
		a[y] -= z
	else:
		a[0] += z
		a[y] -= z
		a[x] += z
		a[n] -= z
for i in range(1, n + 1):
	a[i] += a[i - 1]
print (max(a) + 35) / 36