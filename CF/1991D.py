for t in range(int(input())):
	n = int(input())
	if n < 6:
		z = [1, 2, 2, 3, 3][:n]
	else:
		z = [i % 4 + 1 for i in range(n)]
	print(max(z))
	print(*z)