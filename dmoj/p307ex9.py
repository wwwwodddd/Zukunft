for t in range(int(input())):
	n = int(input())
	if n % 100 != 0 and n % 4 == 0 or n % 400 == 0:
		print(1)
	else:
		print(0)