ans = 0
ab, bc, ca, ac, ba, cb = 0, 0, 0, 1, 0, 0
p = 10 ** 9
def F(x, y):
	return (x - y) * (x + y)
for i in range(1, 10001):
	print i
	L = pow(10, i, p)
	A = pow(3, i, p)
	B = pow(6, i, p)
	C = pow(9, i, p)
	ans += ab * F(B - 1, A - 1)
	ans += bc * F(C - 1, B - 1)
	ans += ca * F(L - A, L - C)
	ans += ac * F(C - 1, A - 1)
	ans += (ba + 1) * F(L - A, L - B)
	ans += cb * F(L - B, L - C)
	ans %= p
	ab, bc, ca, ac, ba, cb = ac + ba, cb + ac, ba + cb, ab + bc + 1, ca + ab + 1, ca + bc + 1
	ab %= p
	bc %= p
	ca %= p
	ac %= p
	ba %= p
	cb %= p

print ans