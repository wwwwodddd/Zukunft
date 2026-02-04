for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	z = 1
	b = a[0] % 2
	for i in range(1, len(a)):
		a[i] %= 2
		if b != a[i]:
			b = a[i]
			z += 1
	print(z)