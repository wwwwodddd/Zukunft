for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	x = 0
	z = []
	for i in range(n):
		if x < a[i]:
			x = a[i]
			z.append(1)
		else:
			z.append(0)
	print(*z)