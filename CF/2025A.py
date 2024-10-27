for t in range(int(input())):
	s = input()
	t = input()
	z = 0
	while z < len(s) and z < len(t) and s[z] == t[z]:
		z += 1
	print(len(s) + len(t) - max(z - 1, 0))