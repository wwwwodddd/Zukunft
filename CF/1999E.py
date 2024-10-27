def F(x):
	b = 1
	c = 1
	z = 0
	while b * 3 <= x:
		z += b * 2 * c
		b *= 3
		c += 1
	return z + (x - b) * c

for t in range(int(input())):
	l, r = map(int, input().split())
	t = l
	z = 0
	while t > 0:
		z += 2
		t //= 3
	print(z + F(r + 1) - F(l + 1))