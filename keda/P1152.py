n, m = map(int, input().split())
z = 10000
for i in range(n):
	x, y = map(int, input().split())
	z = min(z, x / y)
print('%.6f' % (m * z))