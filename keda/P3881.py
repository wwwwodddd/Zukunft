p = 1000000007
x, y, z = 1, 0, 0
for i in range(int(input())):
	x, y, z = x * 8 % p, (y * 9 + x) % p, (z * 10 + y * 2) % p
print(z)