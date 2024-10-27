for t in range(int(input())):
	n = int(input())
	a = [0] + list(map(int, input().split()))
	v = [0 for i in range(n + 1)]
	z = 0
	for i in range(1, n + 1):
		c = 0
		while v[i] == 0:
			v[i] = 1
			i = a[i]
			c += 1
		if c > 2:
			z += (c - 1) // 2
	print(z)