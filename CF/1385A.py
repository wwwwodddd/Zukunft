for t in range(int(input())):
	a, b, c = sorted(map(int, input().split()))
	if b == c:
		print('YES')
		print(a, a, b)
	else:
		print('NO')
