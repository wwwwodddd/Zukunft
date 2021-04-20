p = 999999937
def mul(A, B):
	C = [[0, 0], [0, 0]]
	for i in [0, 1]:
		for j in [0, 1]:
			for k in [0, 1]:
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % p
	return C

def F(u, n):
	r = int(u ** 0.5)
	if r * r == u:
		return pow(2 * r, n, p)
	if r * r < u:
		r += 1
	b = r * 2
	c = u - r * r
	A = [[2, 2 * r], [0, 0]]
	B = [[0, c], [1, b]]
	while n > 0:
		if n & 1:
			A = mul(A, B)
		B = mul(B, B)
		n >>= 1
	return A[0][0] - 1
# 2
# 2 * r
# r == -b / 2
# b = -2 * r

# u == b * b / 4 - c
# c = (b * b / 4 - u)

def G(n):
	s = 0
	for i in range(1, n + 1):
		if i % 10000 == 0:
			print(i)
		s = (s + F(i, i * i)) % p
	return s % 999999937
print(F(5, 2)) # 27
print(F(5, 5)) # 3935
print(G(1000)) # 163861845
print(G(5000000)) # 700792959