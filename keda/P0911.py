def gan(n):
	if n == 1:
		return 1
	return n - n % 2 + 2 - 2 * gan(n // 2)
print(gan(int(input())))
