for t in range(int(input())):
	a, b, c, d = map(int, input().split())
	if a > b:
		a, b = b, a
	if c > d:
		c, d = d, c
	if a > c:
		a, b, c, d = c, d, a, b
	if a < c < b < d:
		print('YES')
	else:
		print('NO')