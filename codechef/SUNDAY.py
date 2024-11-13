for t in range(int(input())):
	n = int(input())
	z = 8
	for i in map(int, input().split()):
		if i % 7 not in [0, 6]:
			z += 1
	print(z)