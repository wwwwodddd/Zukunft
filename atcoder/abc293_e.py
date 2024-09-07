a, x, m = map(int, input().split())
if a == 1:
	print(x % m)
else:
	print((pow(a, x, m * (a - 1)) - 1) // (a - 1) % m)