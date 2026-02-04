for t in range(int(input())):
	n = int(input())
	if n == 1:
		print(1)
	elif n == 2:
		print(-1)
	else:
		a = list(range(1, n * n + 1, 2)) + list(range(2, n * n + 1, 2))
		for i in range(n):
			print(*a[i * n : i * n + n])
