for t in range(int(input())):
	input()
	z = 0
	l = 0
	for i in map(int, input().split()):
		if l != i:
			l = i
			z += 1
	print(z)
