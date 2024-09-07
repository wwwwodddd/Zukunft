for t in range(int(input())):
	n, s, m = map(int, input().split())
	a = [(0, 0)]
	for i in range(n):
		x, y = map(int, input().split())
		a.append((x, y))
	a.append((m, m))
	for i in range(1, len(a)):
		if a[i][0] - a[i - 1][1] >= s:
			print('YES')
			break
	else:
		print('NO')