def C(n, m):
	z = 1
	for i in range(m):
		z = z * (n - i) // (i + 1);
	return z
n = int(input())
print(C(2 * n, n) // (n + 1))