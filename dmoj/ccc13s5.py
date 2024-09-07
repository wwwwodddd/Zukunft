n = int(input())
z = 0
while n > 1:
	i = 2
	while i <= n:
		if n % i == 0:
			n = n // i * (i - 1)
			z += i - 1
			break
		i += 1
print(z)