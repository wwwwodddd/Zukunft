n = int(input())
z = 0
for i in range(1, n + 1):
	z += i * (i + 1) // 2
print(z)