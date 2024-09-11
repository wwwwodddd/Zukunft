n = int(input())
z = 0
for i in range(n):
	x = int(input())
	y = int(input())
	if 5 * x - 3 * y > 40:
		z += 1
if z == n:
	print(str(z) + '+')
else:
	print(z)