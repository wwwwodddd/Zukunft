for t in range(int(input())):
	n, k = map(int, input().split())
	z = -1
	for i in map(int, input().split()):
		if k % i == 0:
			z = max(z, i)
	print(z)