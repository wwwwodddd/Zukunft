for t in range(int(input())):
	n = int(input())
	z = []
	q = [[], []]
	c = 0
	for i in map(int, input()):
		if not q[i]:
			c += 1
			q[i].append(c)
		z.append(q[i][-1])
		q[1 - i].append(q[i].pop())
	print(c)
	print(*z)