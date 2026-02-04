for t in range(int(input())):
	n, m, k = map(int, input().split())
	print(max(n * (m - (k + n - 1) // n), m * (n - (k + m - 1) // m)))