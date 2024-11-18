for t in range(int(input())):
	n = int(input())
	if n < 5:
		print(-1)
	else:
		a = list(range(7, n + 1, 2)) + [1, 3, 5, 4, 2] + list(range(6, n + 1, 2))
		print(*a)