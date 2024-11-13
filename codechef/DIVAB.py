for t in range(int(input())):
	a, b, n = map(int, input().split())
	if a % b == 0:
		print(-1)
	else:
		n = (n + a - 1) // a * a
		while n % b == 0:
			n += a
		print(n)
