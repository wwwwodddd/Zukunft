a, p = map(int, input().split())
a %= p
if a == 0:
	print('impossible')
else:
	print(pow(a, p - 2, p))