for t in range(int(input())):
	l, r, k = map(int, input().split())
	if (r + 1) // 2 - l // 2 <= k or l == r > 1:
		print('YES')
	else:
		print('NO')