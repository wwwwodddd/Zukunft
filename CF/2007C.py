import math
for t in range(int(input())):
	n, a, b = map(int, input().split())
	g = math.gcd(a, b)
	s = set()
	for i in map(int, input().split()):
		s.add(i % g)
	s = sorted(s)
	z = s[-1] - s[0]
	for i in range(1, len(s)):
		z = min(z, g - (s[i] - s[i - 1]))
	print(z)