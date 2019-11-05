n = 10 ** 7
p = 10 ** 9 + 7
m = pow(2, n, p)
f = [0 for i in range(n + 1)]
f[0] = 1
s = 1
for i in range(2, n + 1):
	s = s * (m - i + 1) % p
	f[i] = (s - f[i - 1] - f[i - 2] * (i - 1) * (m - i + 1)) % p
s = s * (m - n) % p
print ((s - f[n]) % p)