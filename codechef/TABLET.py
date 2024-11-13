for t in range(int(input())):
	n, b = map(int, input().split())
	z = 0
	for i in range(n):
		w, h, p = map(int, input().split())
		if p <= b:
			z = max(z, w * h)
	if z > 0:
		print(z)
	else:
		print('no tablet')
