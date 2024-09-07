a, b = map(int, input().split())
if a > b:
	a, b = b, a
if a / 3 ** 0.5 * 2 < b:
	print(a / 3 ** 0.5 * 2)
else:
	print(2 * (a * a + b * b - a * b * 3 ** 0.5) ** 0.5)