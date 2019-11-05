p = 1234567891011
def F(n):
	if n == 0:
		return (0, 1)
	elif n%2 == 1:
		x, y = F(n - 1)
		return (y, (x + y) % p)
	else:
		x, y = F(n / 2)
		return ((2 * y - x) * x % p, (x * x + y * y) % p)
z = 0
for i in range(100000):
	n = input()
	z += F(n)[0]
	z %= p
print z