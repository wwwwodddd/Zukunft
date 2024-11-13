for t in range(int(input())):
	n = int(input())
	if n % 5:
		print(-1)
	else:
		print((n + 5) // 10)
