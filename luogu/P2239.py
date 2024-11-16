n, i, j = map(int, input().split())
d = min(i - 1, j - 1, n - i, n - j)
z = (n - d) * d * 4
if d == i - 1:
	print(z + j - d)
elif d == n - j:
	print(z + n - 3 * d + i - 1)
elif d == n - i:
	print(z + 2 * n - 5 * d + n - j - 1)
else:
	print(z + 3 * n - 7 * d + n - i - 2)
