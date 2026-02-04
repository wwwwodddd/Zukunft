x, y, z = 1, 1, 2
for i in range(int(input())):
	x, y, z = y, z, x + z
print(x)