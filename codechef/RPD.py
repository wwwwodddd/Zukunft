for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	z = 0
	for i in range(len(a)):
		for j in range(i):
			z = max(z, sum(map(int, str(a[i] * a[j]))))
	print(z)