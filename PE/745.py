p = 1000000007
def S(n):
	m = int(n ** 0.5)
	s = [0 for i in range(m + 1)]
	z = 0
	for i in range(1, m + 1)[::-1]:
		s[i] = n // i // i
		for j in range(i * 2, m + 1, i):
			s[i] -= s[j]
		z = (z + s[i] * i * i) % p
	return z
print(S(10))
print(S(100))
print(S(10 ** 14))

