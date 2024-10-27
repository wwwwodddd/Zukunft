for t in range(int(input())):
	a, b, c = sorted(map(int, input().split()))
	if b + c > 9:
		print('YES')
	else:
		print('NO')
