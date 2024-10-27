for t in range(int(input())):
	n = int(input())
	a = [[1, 1], [1, 2], [3, 1]]
	for x, y in a[:n]:
		print(x, y)
	for i in range(4, n + 1):
		print(i, i)