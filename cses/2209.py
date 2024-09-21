from math import gcd
n, m = map(int, input().split())
p = 1000000007
z = 0
for i in range(n):
	z = (z + pow(m, gcd(i, n), p)) % p
print(z * pow(n, p - 2, p) % p)