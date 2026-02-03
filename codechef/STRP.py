for t in range(int(input())):
	n = int(input())
	s = input()
	z = 0
	i = 0
	while i < len(s):
		z += 1
		if i + 1 < len(s) and s[i] == s[i + 1]:
			i += 1
		i += 1
	print(z)