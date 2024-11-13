for t in range(int(input())):
	a, b = map(int, input().split())
	if a < b:
		a, b = b, a
	c = a // b
	if a % b == 0 and (c == (c & -c)):
		print('YES')
	else:
		print('NO')
