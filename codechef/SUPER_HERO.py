for t in range(int(input())):
	h, k = map(int, input().split())
	z = 0
	i = 2
	while i * i <= h:
		while h % i == 0:
			h //= i
			z += 1
		i += 1
	if h > 1:
		z += 1
	while k > 1:
		k //= 2
		z += 1
	print(z)