for t in range(int(input())):
	n = int(input())
	a = []
	for i in range(n):
		x, y = map(int, input().split())
		if x <= 10:
			a.append((y, i + 1))
	print(max(a)[1])
