for t in range(int(input())):
	n = int(input())
	p = [set(), set()]
	for i in range(n):
		x, y = map(int, input().split())
		p[y].add(x)
	z = len(p[0] & p[1]) * (n - 2)
	for i in p[0]:
		if i - 1 in p[1] and i + 1 in p[1]:
			z += 1
	for i in p[1]:
		if i - 1 in p[0] and i + 1 in p[0]:
			z += 1
	print(z)