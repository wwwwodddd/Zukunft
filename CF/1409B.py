def F(a, b, x, y, n):
	t = min(a - x, n)
	a -= t
	n -= t
	t = min(b - y, n)
	b -= t
	n -= t
	return a * b
for t in range(int(input())):
	a, b, x, y, n = map(int, input().split())
	print(min(F(a, b, x, y, n), F(b, a, y, x, n)))