for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = a.copy()
	for i in range(n - 1, 0, -1):
		b[i - 1] = min(b[i - 1], b[i])
	m = 0
	z = []
	for i in range(n):
		m = max(m, a[i])
		if i == n - 1 or m <= b[i + 1]:
			z += [m] * (i - len(z) + 1)
	print(*z)
