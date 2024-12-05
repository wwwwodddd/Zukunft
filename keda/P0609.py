n = int(input())
i = 2
z = ''
while i <= n:
	c = 0
	while n % i == 0:
		c += 1
		n //= i
	if c:
		if z:
			z += '*'
		z += str(i)
		if c > 1:
			z += '^' + str(c)
	i += 1
print(z)