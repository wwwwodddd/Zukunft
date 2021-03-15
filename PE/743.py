p = 1000000007
def F(n):
	r = 1
	for i in range(1, n + 1):
		r = r * i % p
	return r
def A(k, n):
	assert n % k == 0
	z = 0
	c = 1
	u = pow(2, n, p)
	r = pow(2, n // k * 2, p)
	r = pow(r, p - 2, p)
	v = [0 for i in range(k // 2 + 2)]
	v[1] = 1
	for i in range(2, k // 2 + 2):
		v[i] = v[p % i] * (p - p // i) % p
	for i in range(k // 2 + 1):
		j = (k - 2 * i)
		z = (z + c * u) % p
		u = u * r % p
		c = c * (k - 2 * i) % p * (k - 2 * i - 1) % p * v[i + 1] % p * v[i + 1] % p
	return z
print(A(3, 9))
print(A(4, 20))
print(A(10 ** 8, 10 ** 16))