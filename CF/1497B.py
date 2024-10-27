for t in range(int(input())):
	n, m = map(int, input().split())
	c = [0 for i in range(m)]
	for i in map(int, input().split()):
		c[i % m] += 1
	z = 0
	if c[0]:
		z += 1
	for i in range(1, (m + 1) // 2):
		if c[i] > 0 or c[m - i] > 0:
			z += max(max(c[i], c[m - i]) - min(c[i], c[m - i]), 1)
	if m % 2 == 0 and c[m // 2] > 0:
		z += 1
	print(z)
