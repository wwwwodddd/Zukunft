for t in range(int(input())):
	n, x = map(int, input().split())
	if n % 2 == 1 and x % 2 == 0:
		print('NO')
	else:
		print('YES')
