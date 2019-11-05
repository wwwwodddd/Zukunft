n = 784
for i in range(n + 1):
	for j in range(n - i + 1):
		k = n - i - j
		if i * i + j * j + i * j == 399 ** 2:
			if i * i + k * k + i * k == 455 ** 2:
				if j * j + k * k + j * k == 511 ** 2:
					print i, j, k
					print i * i + j * j + i * j
