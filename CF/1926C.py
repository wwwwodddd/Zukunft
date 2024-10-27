def F(n, x):
	t = 1
	z = 0
	while t < n:
		z += n // 10 // t * t
		if n // t % 10 > x:
			z += t
		elif n // t % 10 == x:
			z += n % t
		t *= 10
	return z
for t in range(int(input())):
	n = int(input()) + 1
	z = 0
	for i in range(1, 10):
		z += F(n, i) * i
	print(z)
