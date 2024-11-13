a, b, c, x = map(int, input().split())
if a * b * c < x ** 3:
	print('Cube')
elif a * b * c > x ** 3:
	print('Cuboid')
else:
	print('Equal')