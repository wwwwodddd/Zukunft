n, h, x = map(int, input().split())
if max(map(int, input().split())) + x >= h:
	print('YES')
else:
	print('NO')