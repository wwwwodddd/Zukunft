for t in range(int(input())):
	n = int(input())
	s = input()
	z = 0
	for i in range(n // 2):
		if s[i] != s[n - i - 1]:
			z += 1
	print((z + 1) // 2)