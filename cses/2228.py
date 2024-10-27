n, k = map(int, input().split())
p = 1000000007
z = 0
c = 1
for i in range(k):
	z = (z + c * pow(k - i, n, p)) % p
	c = c * (i - k) * pow(i + 1, p - 2, p) % p
print(z)