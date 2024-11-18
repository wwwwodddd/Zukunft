for t in range(int(input())):
	n, k = map(int, input().split())
	z = 0
	for i in map(int, input().split()):
		if i == z + 1:
			z += 1
	print((n - z + k - 1) // k)