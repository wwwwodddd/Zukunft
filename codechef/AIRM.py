for t in range(int(input())):
	input()
	c = [0 for i in range(1440)]
	for i in list(map(int, input().split())):
		c[i] += 1
	for i in list(map(int, input().split())):
		c[i] += 1
	print(max(c))