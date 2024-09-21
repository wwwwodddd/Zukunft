for k in range(1, int(input()) + 1):
	z = k * k * (k * k - 1) // 2
	z -= (k - 1) * (k - 2) * 4
	print(z)