for t in range(int(input())):
	n = int(input())
	for i in range(n):
		a = list(range(i * n + 1, i * n + n + 1))
		if n % 2 == 0 and i % 2 == 1:
			a = a[::-1]
		print(*a)