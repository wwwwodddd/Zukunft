for t in range(int(input())):
	n = int(input())
	i = 2
	while i * i <= n:
		if n % i == 0:
			print(n // i, n // i * (i - 1))
			break
		i += 1
	else:
		print(1, n - 1)
