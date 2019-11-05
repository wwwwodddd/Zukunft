#a(n) = SUM (m+k+1)!*binomial(m+k,m)*2^k*(k+v1+v2)!*(m+k)!,
#where the sum is taken over v1,v2 each from 0 to 1,
#and over nonnegative m,k such that 2*m+3*k = n-1-v1-v2. 

n = 10 ** 6
v = [0 for i in range(2 * n + 1)]
f = [0 for i in range(2 * n + 1)]
p = 10 ** 8 + 7
v[1] = 1
for i in range(2, 2 * n + 1):
	v[i] = v[p % i] * (p - p / i) % p

f[0] = 1
v[0] = 1
for i in range(1, 2 * n + 1):
	f[i] = f[i - 1] * i % p
	v[i] = v[i - 1] * v[i] % p

def C(x, y):
	return f[x] * v[y] * v[x - y] % p

def F(n):
	z = 0
	for v1 in range(2):
		for v2 in range(2):
			m = 0
			while 2 * m <= n - 1 - v1 - v2:
				if (n - 1 - v1 - v2 - 2 * m) % 3 == 0:
					k = (n - 1 - v1 - v2 - 2 * m) / 3
					assert 2*m+3*k == n-1-v1-v2
					z = (z + f[m + k + 1] * C(m + k, m) * pow(2, k, p) * f[k + v1 + v2] * f[m + k]) % p
				m += 1
	return z

print F(10 ** 6)