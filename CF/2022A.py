for t in range(int(input())):
	n, r = map(int, input().split())
	z = 0
	c = 0
	for i in map(int, input().split()):
		z += i // 2 * 2
		r -= i // 2
		if i & 1:
			c += 1
	print(z + min(c, 2 * r - c))