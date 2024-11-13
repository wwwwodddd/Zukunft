for t in range(int(input())):
	a, b, x, y = map(int, input().split())
	if -y <= b - a <= x:
		print('YES')
	else:
		print('NO')