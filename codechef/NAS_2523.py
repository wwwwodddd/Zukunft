for t in range(int(input())):
	n = int(input())
	if n % 2:
		print(-1)
	else:
		print(*range(n, 0, -1))
