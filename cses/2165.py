n = int(input())
def zuo(d, x, y, z):
	if d == 1:
		print(x, z)
	else:
		zuo(d - 1, x, z, y)
		print(x, z)
		zuo(d - 1, y, x, z)
print(2 ** n - 1)
zuo(n, 1, 2, 3)