def F(t):
	s = str(t)
	z = 0
	for i in range(1, len(s) + 1):
		if s[:i] == s[-i:]:
			z += 10 ** i
	return z - len(s) + 1


ans = 0
for i in range(2, 1000000):
	ans += F(10 ** 16 / i)
print ans
