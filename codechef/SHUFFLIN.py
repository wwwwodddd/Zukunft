for t in range(int(input())):
	n = int(input())
	c = [0, 0]
	for i in map(int, input().split()):
		c[i % 2] += 1
	print(min(c[1], n // 2) + min(c[0], (n + 1) // 2))