for t in range(int(input())):
	a, b, c = map(int, input().split())
	if a + b == c:
		print('YES')
	else:
		print('NO')
