n, k = map(int, input().split())
z = 1
for i in range(2, n + 1):
	c = 0
	while n % i == 0:
		n /= i
		c += 1
	z = z * (pow(i, c * k + 1) - 1) // (i - 1)
print(z)