n = int(input())
x = y = 0
z = 100
for i in range(n):
	y = x
	x = int(input())
	if i > 0:
		z *= max(1, y / x)
print('%.0f' % z)