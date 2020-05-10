n = input() % 6
x = input()
a = [0, 1, 2]
for i in range(n):
	if i % 2 == 0:
		a[0], a[1] = a[1], a[0]
	else:
		a[2], a[1] = a[1], a[2]
print a[x]
