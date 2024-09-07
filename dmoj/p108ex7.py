for t in range(int(input())):
	n = int(input())
	if n <= 30:
		print(38)
	elif n <= 50:
		print(55)
	elif n <= 100:
		print(73)
	else:
		print(25 + (n + 49) // 50 * 24)