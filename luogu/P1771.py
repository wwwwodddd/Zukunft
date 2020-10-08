k, x = map(int, input().split())
x = pow(x, x, 1000) - 1
z = 1
for i in range(k - 1):
	z = z * (x - i) // (i + 1)
print(z)