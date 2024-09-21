e = [0, 1, 0, 0, 0, 0]
o = [1, 0, 0, 0, 0, 0]
p = 1000000007
def mul(a, b):
	c = [0 for i in range(11)]
	for i in range(6):
		for j in range(6):
			c[i + j] = (c[i + j] + a[i] * b[j]) % p
	for i in range(10, 5, -1):
		for j in range(1, 7):
			c[i - j] = (c[i - j] + c[i]) % p
		c[i] = 0
	return c[:6]

def F(n):
	if n == 0:
		return o
	elif n & 1:
		a = F(n - 1)
		return mul(a, e)
	else:
		a = F(n // 2)
		return mul(a, a)

print(F(int(input()) + 6)[0])