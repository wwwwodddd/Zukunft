a, b = map(int, input().split())
if a < b:
	print(0)
else:
	p = 1000000007
	x = 1
	y = 1
	for i in range(b):
		x = x * (i + 1) % p
		y = y * (a - i) % p
	print(y * pow(x, p - 2, p) * pow(2, a - b, p) % p)