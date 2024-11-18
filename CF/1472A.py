for t in range(int(input())):
	w, h, n = map(int, input().split())
	if (w & -w) * (h & -h) >= n:
		print('YES')
	else:
		print('NO')
