for t in range(int(input())):
	z, y, a, b, c = map(int, input().split())
	if y + a + b + c <= z:
		print('YES')
	else:
		print('NO')
