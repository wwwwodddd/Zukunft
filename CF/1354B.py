for t in range(int(input())):
	s = input()
	c = [0, 0, 0, 0]
	j = 0
	z = len(s) + 1
	for i in range(len(s)):
		c[int(s[i])] += 1
		while c[1] and c[2] and c[3]:
			z = min(z, i - j + 1)
			c[int(s[j])] -= 1
			j += 1
	if z > len(s):
		z = 0
	print(z)
