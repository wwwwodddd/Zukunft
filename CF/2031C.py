for t in range(int(input())):
	n = int(input())
	if n % 2 == 0:
		a = [i // 2 + 22 for i in range(n)]
	elif n < 27:
		a = [-1]
	else:
		a = [1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 13, 12, 12, 1, 13] + [i // 2 + 22 for i in range(n - 27)]
	print(*a)
