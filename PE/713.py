def L(n):
	z = 0
	for i in range(1, n):
		z += (n // i) * (n // i - 1) // 2 * (i - (n % i)) + (n // i + 1) * (n // i) // 2 * (n % i)
	return z
print(L(10000000))