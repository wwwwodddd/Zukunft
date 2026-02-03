for t in range(int(input())):
	n = int(input())
	if n % 3 == 0:
		print(n // 3 * 5)
	elif n % 3 == 2:
		print(n // 3 * 5 + 4)
	else:
		print((n - 4) // 3 * 5 + 8)