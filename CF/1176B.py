for t in range(int(input())):
	input()
	c = [0, 0, 0]
	for i in map(int, input().split()):
		c[i % 3] += 1
	print(c[0] + min(c[1], c[2]) + (max(c[1], c[2]) - min(c[1], c[2])) // 3)
