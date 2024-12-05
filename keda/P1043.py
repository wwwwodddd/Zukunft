n = 100
for i in range(n // 5 + 1):
	for j in range(n // 3 + 1):
		if (n - i - j) == (n - i * 5 - j * 3) * 3:
			print(i, j, n - i - j)