for t in range(int(input())):
	n, a, b = map(int, input().split())
	z = 1e9
	for i in range(n):
		x, y = map(int, input().split())
		z = min(z, abs(a - x) + abs(b - y))
	print(z)