for t in range(int(input())):
	input()
	c = [0, 0, 0, 0]
	for i in map(int, input().split()):
		c[i] += 1
	print(max(c[2] - 1, 0) + min(c[1], c[3]))