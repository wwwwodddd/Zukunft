x, y, a, b = map(int, input().split())
z = 0
for i in range(10000):
	c = a // x + b // y
	z += c
	a = a % x + c
	b = b % y + c
if z >= 10000:
	z = 'INF'
print(z)