for t in range(int(input())):
	n, a, b = map(int, input().split())
	b = min(b, 2 * a)
	print(n // 2 * b + n % 2 * a)