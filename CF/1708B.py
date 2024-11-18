for t in range(int(input())):
	n, l, r = map(int, input().split())
	a = []
	for i in range(1, n + 1):
		if (l - 1) // i * i + i <= r:
			a.append((l - 1) // i * i + i)
		else:
			print('NO')
			break
	else:
		print('YES')
		print(*a)