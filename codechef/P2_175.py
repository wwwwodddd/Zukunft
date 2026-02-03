for t in range(int(input())):
	n = int(input())
	if n == 1:
		print(1)
	elif n % 2:
		print(n // 2)
	else:
		print(n // 2 + 1)