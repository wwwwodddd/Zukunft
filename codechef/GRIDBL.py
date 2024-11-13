for t in range(int(input())):
	n, m = map(int, input().split())
	if n % 2 == 1 and m % 2 == 1:
		print(n + m - 1)
	elif n % 2 == 1:
		print(m)
	elif m % 2 == 1:
		print(n)
	else:
		print(0)
