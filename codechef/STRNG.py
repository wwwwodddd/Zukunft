import math
for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	p = [0 for i in range(n + 1)]
	s = [0 for i in range(n + 1)]
	for i in range(n):
		p[i + 1] = math.gcd(p[i], a[i])
	for i in range(n)[::-1]:
		s[i] = math.gcd(s[i + 1], a[i])
	z = 0
	for i in range(n):
		if math.gcd(p[i], s[i + 1]) != 1:
			z += 1
	print(z)