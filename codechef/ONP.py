for t in range(int(input())):
	s = input()
	z = ''
	i = 1
	def dfs():
		global i
		global z
		if s[i] == '(':
			i += 1
			dfs()
		else:
			z += s[i]
			i += 1
		o = s[i]
		i += 1
		if s[i] == '(':
			i += 1
			dfs()
		else:
			z += s[i]
			i += 1
		z += o
		i += 1
	dfs()
	print(z)