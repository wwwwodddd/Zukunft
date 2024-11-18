for t in range(int(input())):
	a, b, n, s = map(int, input().split())
	if s % n <= b and s <= a * n + b:
		print('YES')
	else:
		print('NO')