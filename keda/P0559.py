n = int(input())
if n & 1:
	print(0, 0)
else:
	print((n + 2) // 4, n // 2)