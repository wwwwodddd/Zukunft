for t in range(int(input())):
	a = []
	for i in range(22):
		x, y = map(int, input().split())
		a.append(x + 20 * y)
	print(a.index(max(a)) + 1)