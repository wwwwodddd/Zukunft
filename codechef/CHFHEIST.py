for t in range(int(input())):
	n, d, p, q = map(int, input().split())
	m = n // d
	print((p + p + (m - 1) * q) * m // 2 * d + n % d * (p + m * q))