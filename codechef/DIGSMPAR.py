def S(n):
	return n if n < 10 else n % 10 + S(n // 10)
for t in range(int(input())):
	z = n = int(input())
	while S(n) % 2 == S(z) % 2:
		z += 1
	print(z)