for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = [100001 + i for i in range(n)]
	d = [b[i] - a[i] for i in range(n)]
	z = []
	for i in range(20):
		o = [1 << i]
		for j in range(n):
			if d[j] >> i & 1:
				o.append(j + 1)
		if len(o) > 1:
			z.append(o)
	print(len(z))
	for o in z:
		print(len(o) - 1, o[0])
		print(*o[1:])