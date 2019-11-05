n, k = 100, 40
n, k = 10000000, 4000000
p = 10 ** 9 + 7
z = 0
c = 1
for i in range(k + 1):
	if i % 2 == 0:
		z = (z + pow(k - i, n, p) * c) % p
	else:
		z = (z - pow(k - i, n, p) * c) % p
	c = c * (n + 1 - i) % p * pow(i + 1, p - 2, p) % p
print z