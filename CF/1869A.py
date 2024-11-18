for t in range(int(input())):
	n = int(input())
	s = input()
	if n & 1:
		print(4)
		print(1, n - 1)
		print(1, n - 1)
		print(2, n)
		print(2, n)
	else:
		print(2)
		print(1, n)
		print(1, n)
