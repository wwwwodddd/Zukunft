def F(n):
	z = 0
	for i in range(n // 4 * 4, n):
		z ^= i
	return z
for t in range(int(input())):
	s, f = map(int, input().split())
	print(F(f + 1) ^ F(s))