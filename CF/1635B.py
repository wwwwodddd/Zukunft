for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split())) + [0]
	z = 0
	for i in range(1, n - 1):
		if a[i - 1] < a[i] > a[i + 1]:
			a[i + 1] = max(a[i], a[i + 2])
			z += 1
	print(z)
	print(*a[:-1])