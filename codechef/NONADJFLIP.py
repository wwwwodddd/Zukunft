for t in range(int(input())):
	n = int(input())
	s = input()
	z = 0
	for i in range(n):
		if s[i] == '1':
			z = max(z, 1)
			if i > 0 and s[i - 1] == '1':
				z = max(z, 2)
	print(z)