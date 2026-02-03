for i in range(int(input())):
	input()
	c = [0 for i in range(101)]
	for i in map(int, input().split()):
		c[i] += 1
	m = max(c)
	for i in range(101):
		if c[i] == m:
			print(i)
			break