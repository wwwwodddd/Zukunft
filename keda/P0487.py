n = int(input())
for i in range(n):
	d = min(i, n - 1 - i)
	print(' ' * d + '*' * (n - d - d))