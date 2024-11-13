for t in range(int(input())):
	n, a, b = map(int, input().split())
	print(n // 2 * a + (n + 1) // 2 * b)