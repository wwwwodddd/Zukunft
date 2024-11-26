for t in range(int(input())):
	n, x = map(int, input().split())
	z = 0
	for i, a in enumerate(map(int, input().split()), 1):
		if a < x:
			z = i
	print(z)