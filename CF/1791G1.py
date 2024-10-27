for t in range(int(input())):
	n, c = map(int, input().split())
	a = list(map(int, input().split()))
	for i in range(n):
		a[i] += i + 1
	a.sort()
	z = 0
	for i in a:
		if c >= i:
			c -= i
			z += 1
		else:
			break
	print(z)