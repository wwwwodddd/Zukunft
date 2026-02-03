for t in range(int(input())):
	n = int(input())
	if n == 1:
		a = [-1]
	elif n % 2 == 0:
		a = [-1, 1] * (n // 2)
	else:
		a = [-1, -1, 2] + [-1, 1] * ((n - 3) // 2)
	print(*a)
