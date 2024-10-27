n, m = map(int, input().split())
for i in range(m):
	x, y = map(int, input().split())
	if x > y:
		x, y = y, x
	print(x, y)