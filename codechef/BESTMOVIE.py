for t in range(int(input())):
	n = int(input())
	z = 1e9
	for i in range(n):
		a, b = map(int, input().split())
		if a >= 7:
			z = min(z, b)
	if z == 1e9:
		z = -1
	print(z)
