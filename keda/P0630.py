x, y = 1, 3
for i in range(1, int(input())):
	x, y = y, (3 * y + 2 * x) % 49999
print(x)