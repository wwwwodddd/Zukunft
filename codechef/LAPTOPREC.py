for t in range(int(input())):
	n = int(input())
	c = [0] * 11
	for i in map(int, input().split()):
		c[i] += 1
	if c.count(max(c)) == 1:
		print(c.index(max(c)))
	else:
		print('CONFUSED')