def phi(x):
	z = x
	i = 2
	while i * i <= x:
		if x % i == 0:
			z = z // i * (i - 1)
			while x % i == 0:
				x //= i
		i += 1
	if x > 1:
		z = z // x * (x - 1)
	return z
print(phi(int(input())))