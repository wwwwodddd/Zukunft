for t in range(int(input())):
	n, x = map(int, input().split())
	if x < 3 or x % 2 == 0:
		print(0)
	else:
		n += 1
		m = 1
		while x ** m <= n:
			m += 1
		z = 0
		for i in range(m, -1, -1):
			if n >= x ** i:
				z += 2 ** i
				if n >= (x - 1) * x ** i:
					n -= (x - 1) * x ** i
				else:
					break
		print(z - 1)