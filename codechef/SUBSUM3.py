for t in range(int(input())):
	input()
	c = [0, 0, 0]
	for i in map(int, input().split()):
		c[i % 3] += 1
	if c[0] > 0 or c[1] > 2 or c[2] > 2 or c[1] > 0 and c[2] > 0:
		print('Yes')
	else:
		print('No')
