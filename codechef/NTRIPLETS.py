for t in range(int(input())):
	n = int(input())
	i = 2
	while i * i < n:
		if n % i == 0:
			print(1, i, n // i)
			break
		i += 1
	else:
		print(-1)