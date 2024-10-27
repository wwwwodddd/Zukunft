for t in range(int(input())):
	n = int(input())
	if n % 7 == 0:
		print(n)
	else:
		n = n // 10 * 10 + 9
		print(n - n % 7)