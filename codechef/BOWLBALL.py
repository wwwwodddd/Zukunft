for t in range(int(input())):
	n, x, y = map(int, input().split())
	z = 0
	for i in map(int, input().split()):
		if x <= i <= y:
			z += 1
	print(z)