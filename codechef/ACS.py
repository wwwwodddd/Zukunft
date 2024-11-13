for t in range(int(input())):
	n = int(input())
	n = n % 100 + n // 100
	if n > 10:
		n = -1
	print(n)