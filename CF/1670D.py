for t in range(int(input())):
	n = int(input())
	L = 0
	R = 10 ** 5
	while L < R - 1:
		M = (L + R) // 2
		a = M // 3
		b = (M + 1) // 3
		c = (M + 2) // 3
		if (a * b + b * c + c * a) * 2 >= n:
			R = M
		else:
			L = M
	print(R)