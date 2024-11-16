for t in range(int(input())):
	n, k, d = map(int, input().split())
	if d & 1:
		print((n + 1) * (n + 1) // 4)
	else:
		print(n * (n + 1) // 2)