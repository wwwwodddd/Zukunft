for t in range(int(input())):
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	z = 0
	c = 0
	for i in a:
		if i >= k:
			z += i
		elif i == 0 and z > 0:
			z -= 1
			c += 1
	print(c)