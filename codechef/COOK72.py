a, b, c, d = sorted(map(int, input().split()))
if a * d == b * c:
	print('Possible')
else:
	print('Impossible')