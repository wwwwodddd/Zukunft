for t in range(int(input())):
	n, m = map(int, input().split())
	s = input()
	t = input()
	z = m
	for i in range(n - m + 1):
		c = 0
		for j in range(m):
			c += (s[i + j] != t[j])
		z = min(z, c)
	print(z)