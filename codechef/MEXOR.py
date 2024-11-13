for t in range(int(input())):
	n = int(input()) + 1
	while n & n - 1:
		n -= n & -n
	print(n)