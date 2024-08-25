n, m = map(int, input().split())
a = [0] + list(map(int, input().split())) + [0 for i in range(m)]
f = [0 for i in range(n + m + 1)]
g = [0 for i in range(n + m + 1)]
h = [0 for i in range(n + m + 1)]
for i in range(1, n + m + 1):
	if (i - 1) % m == 0:
		g[i] = a[i]
	else:
		g[i] = max(g[i - 1], a[i])
	f[i] = g[i]
for i in range((n + m - 1) // m * m, 0, -1):
	if i % m == 0:
		h[i] = a[i]
	else:
		h[i] = max(h[i + 1], a[i])
for i in range(2 * m, n + m, m):
	# from f[i - m - m + 1] .. f[i - m] to if[i - m + 1] .. f[i]
	x = 0
	y = 0
	for j in range(i, i - m, -1):
		if j < i:
			x = max(x, f[j - m] + h[j - m + 1])
		y = max(y, f[j - m])
		f[j] = max(x, y + g[j])
print(f[n])