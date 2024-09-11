x, y = map(int, input().split())
z = x / y
for i in range(int(input())):
	x, y = map(int, input().split())
	z = min(z, x / y)
print('%.2f' % (z * 1000))
