n = int(input())
z = 0
for i in range(0, n + 1, 5):
	if (n - i) % 4 == 0:
		z += 1
print(z)