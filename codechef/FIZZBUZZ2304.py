for t in range(int(input())):
	n, k = map(int, input().split())
	a = [0] + list(map(int, input().split()))
	for i in range(n):
		a[i + 1] = a[i + 1] % 2 + a[i]
	z = 0
	for i in range(k, n + 1):
		if a[i] > a[i - k]:
			z += 1
	print(z)
