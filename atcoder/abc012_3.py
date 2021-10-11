n = 2025 - int(input())
for i in range(1, 10):
	for j in range(1, 10):
		if i * j == n:
			print(i, 'x', j)