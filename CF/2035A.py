for t in range(int(input())):
	n, m, r, c = map(int, input().split())
	print(n * m - (r - 1) * m - c + (n - r) * (m - 1))