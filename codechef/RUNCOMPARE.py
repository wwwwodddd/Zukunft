for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	z = 0
	for i in range(n):
		if a[i] <= 2 * b[i] and b[i] <= 2 * a[i]:
			z += 1
	print(z)