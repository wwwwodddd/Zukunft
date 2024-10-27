for t in range(int(input())):
	n, m = map(int, input().split())
	a = list(map(int, input().split()))
	z = 0
	for i in a:
		if i <= m:
			m -= i
			z += 1
		else:
			break
	print(z)
