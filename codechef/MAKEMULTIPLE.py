for t in range(int(input())):
	a, b = map(int, input().split())
	if a * 2 <= b or a == b:
		print('YES')
	else:
		print('NO')
