for t in range(int(input())):
	n = int(input())
	if n == 1:
		print(1)
	elif n % 2 == 0:
		print(2)
	else:
		print(n * n // 2 + 2)