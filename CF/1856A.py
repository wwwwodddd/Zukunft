for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = 0
	for i in range(1, n):
		if a[i - 1] > a[i]:
			z = max(z, a[i - 1])
	print(z)