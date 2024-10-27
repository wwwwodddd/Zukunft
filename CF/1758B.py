for t in range(int(input())):
	n = int(input())
	if n & 1:
		a = [1] * n
	else:
		a = [2] * (n - 2) + [1, 3]
	print(*a)
