for t in range(int(input())):
	n = int(input())
	c = [0 for i in range(n + 1)]
	for i in map(int, input().split()):
		c[i] += 1
	o = 1
	z = 0
	while c[z]:
		if c[z] == 1:
			if o == 1:
				o -= 1
			else:
				break
		z += 1
	print(z)