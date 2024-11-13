for t in range(int(input())):
	a, b, c, m = map(int, input().split())
	a, b, c = sorted([a, b, c])
	if a + m < b and b + m < c:
		print('NO')
	else:
		print('YES')