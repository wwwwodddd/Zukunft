for t in range(int(input())):
	n, m = map(int, input().split())
	if n > m:
		print(m + m + 1)
	else:
		print(-1)
