for t in range(int(input())):
	a, b, c = sorted(map(int, input().split()))
	if a + b == c or a == b and c % 2 == 0 or b == c and a % 2 == 0:
		print('YES')
	else:
		print('NO')
