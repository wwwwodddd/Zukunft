p = 1000000007
for t in range(int(input())):
	n, m = map(int, input().split())
	c = 1
	z = 0
	w = []
	for i in range(1, m + 1):
		if i < n:
			w.append(z)
		else:
			z = (z + c * pow(2, p - 1 - i, p)) % p
			w.append(z)
			c = c * i * pow(i - n + 1, p - 2, p) % p
	print(*w)