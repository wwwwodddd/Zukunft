for t in range(int(input())):
	n, k = map(int, input().split())
	if (n * (n + 1) // 2 - (n - k) * (n - k + 1) // 2) % 2 == 0:
		print('YES')
	else:
		print('NO')
