xa, xb, ya, yb = map(int, input().split())
if (yb + xa - 1) // xa >= (ya + xb - 1) // xb:
	print('YES')
else:
	print('NO')
