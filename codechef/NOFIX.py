for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = 0
	for i in range(n):
		if i + 1 == a[i] - z:
			z += 1
	print(z)