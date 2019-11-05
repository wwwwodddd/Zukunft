c = 1
m = 10 ** 7
n = 10 ** 12
p = 1000000007
z = 0
def F(x):
	if x == 0:
		return 1
	if x == 1:
		return n + 1
	return (pow(x, n + 1, p) - 1) * pow(x - 1, p - 2, p) % p
for i in range(m):
	c = c * (m - i) * pow(i + 1, p - 2, p) % p
	if i % 2 == 0:
		z = (z + c * F(m - i - 1)) % p
	else:
		z = (z - c * F(m - i - 1)) % p
print z