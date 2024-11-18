for t in range(int(input())):
	n, k = map(int, input().split())
	if n % 2 == 0 or n >= k and (n - k) % 2 == 0:
		print('YES')
	else:
		print('NO')