for t in range(int(input())):
	n, k = map(int, input().split())
	z = ''
	for i in map(int, input().split()):
		if k >= i:
			k -= i
			z += '1'
		else:
			z += '0'
	print(z)