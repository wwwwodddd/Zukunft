for t in range(int(input())):
	n, k = map(int, input().split())
	c = [0 for i in range(k + 1)]
	for i in range(k):
		x, y = map(int, input().split())
		c[x] += y
	c.sort()
	print(sum(c[-n:]))
