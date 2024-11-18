for t in range(int(input())):
	n, c, d = map(int, input().split())
	b = sorted(map(int, input().split()))
	a = sorted(b[0] + i * c + j * d for i in range(n) for j in range(n))
	if a == b:
		print('YES')
	else:
		print('NO')