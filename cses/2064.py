n = int(input())
if n % 2 == 0:
	n //= 2
	x = 1
	y = n + 1
	p = 1000000007
	for i in range(1, 2 * n + 1):
		x = x * i % p
	for i in range(1, n + 1):
		y = y * i % p
		y = y * i % p
	print(x * pow(y, p - 2, p) % p)
else:
	print(0)