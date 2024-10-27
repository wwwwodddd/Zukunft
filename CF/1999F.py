p = 1000000007
n = 200000
fac = [0 for i in range(n + 1)]
fac[0] = 1
for i in range(1, n + 1):
	fac[i] = fac[i - 1] * i % p
invfac = [0 for i in range(n + 1)]
invfac[n] = pow(fac[n], p - 2, p)
for i in range(n)[::-1]:
	invfac[i] = invfac[i + 1] * (i + 1) % p

def C(n, m):
	if m < 0 or m > n:
		return 0
	return fac[n] * invfac[m] % p * invfac[n - m] % p

for t in range(int(input())):
	n, k = map(int, input().split())
	c = sum(map(int, input().split()))
	z = 0
	for i in range((k + 1) // 2, k + 1):
		z = (z + C(c, i) * C(n - c, k - i)) % p
	print(z)
