for t in range(int(input())):
	n = int(input())
	while n & (n - 1):
		n -= n & -n
	print(n - 1)