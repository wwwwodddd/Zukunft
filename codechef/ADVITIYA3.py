for t in range(int(input())):
	n, k = map(int, input().split())
	z = k
	for i in map(int, input().split()):
		if i >= k:
			z = min(z, i % k)
	if z == k:
		z = -1
	print(z)