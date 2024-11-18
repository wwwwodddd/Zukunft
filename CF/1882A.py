for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = 0
	for i in a:
		z += 1
		if i == z:
			z += 1
	print(z)
