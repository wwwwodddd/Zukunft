for t in range(int(input())):
	n = int(input())
	a = [1] + [2 ** i for i in range(n)]
	print(*a)