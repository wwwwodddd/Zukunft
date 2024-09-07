def F(n, b):
	if b < 2:
		return False
	while n > 0:
		if n % b > 1:
			return False
		n //= b
	return True
t = int(input())
for tt in range(t):
	n = int(input())
	s = {n, n - 1}
	for d in range(2, 61):
		s.add(int(n ** (1 / d)))
		s.add(int(n ** (1 / d)) + 1)
	z = 0
	for b in s:
		if F(n, b):
			z += 1
	print(z)