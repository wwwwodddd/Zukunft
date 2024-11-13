for t in range(int(input())):
	n = int(input())
	a = [0] + list(map(int, input().split()))
	b = list(map(int, input().split()))
	z = 0
	for i in range(n):
		if a[i + 1] - a[i] >= b[i]:
			z += 1
	print(z)
