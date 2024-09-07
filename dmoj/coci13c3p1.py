x, y = 1, 0
for i in range(int(input())):
	x, y = y, x + y
print(x, y)