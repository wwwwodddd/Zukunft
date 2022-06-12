for t in range(int(input())):
	n = int(input())
	l = 1
	r = n
	z = []
	for i in range(n):
		if i & 1:
			z.append(r)
			r -= 1
		else:
			z.append(l)
			l += 1
	print(*z[::-1])