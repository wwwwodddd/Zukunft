for t in range(int(input())):
	n, k = map(int, input().split())
	z = 0
	for i in range((n + 1) // 2, n + 1):
		x, y = n, i
		for j in range(k - 2):
			x, y = y, x - y
			if y < 0 or x < y:
				break
		else:
			z += 1
	print(z)