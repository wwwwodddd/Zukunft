for t in range(int(input())):
	a, b, c = map(int, input().split())
	if a == b or b == c:
		print('NO')
	else:
		print('YES')
