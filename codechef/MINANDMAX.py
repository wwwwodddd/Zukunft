for t in range(int(input())):
	n = int(input())
	m = n // 2
	print((m + 1) * m + n % 2 * (n + 1) // 2)
