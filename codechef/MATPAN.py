for t in range(int(input())):
	a = list(map(int, input().split()))
	s = set(input())
	z = 0
	for i in range(26):
		c = chr(i + 97)
		if c not in s:
			z += a[i]
	print(z)