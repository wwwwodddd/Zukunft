n = int(input())
r = int(n ** (1 / 3) + 0.5)
if r ** 3 == n:
	print('Yes')
else:
	print('No')