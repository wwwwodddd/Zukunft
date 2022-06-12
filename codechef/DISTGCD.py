for t in range(int(input())):
	a, b = map(int, input().split())
	x = abs(a - b)
	i = 1
	z = 0
	while i * i <= x:
		if x % i == 0:
			z += 1
			if i * i < x:
				z += 1
		i += 1
	print(z)