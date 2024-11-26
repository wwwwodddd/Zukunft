for t in range(int(input())):
	n, d = map(int, input().split())
	z = 0
	b = 0
	for i in map(int, input().split()):
		if b != (i > d):
			z += 1
			b ^= 1
	print(z)