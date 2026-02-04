for t in range(int(input())):
	n, x, k = map(int, input().split())
	a = sorted(map(int, input().split()))[:n - k]
	x += k * 100
	z = 1
	for i in a:
		if i > x:
			z += 1
	print(z)