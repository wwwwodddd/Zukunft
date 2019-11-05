p = 123454321
def mul(a, b):
	w = [[0 for i in range(3)] for j in range(3)]
	for i in range(3):
		for j in range(3):
			for k in range(3):
				w[i][j] += a[i][k] * b[k][j]
				w[i][j] %= p
	return w
def pw(a, n):
	w = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
	while n > 0:
		if n % 2 == 1:
			w = mul(w, a)
		a = mul(a, a)
		n /= 2
	return w

def S(n):
	a = [[0, 1, 1], [0, 0, 0], [0, 0, 0]]
	b = [[1, 0, 0], [1, 1000000, 0], [0, 1, 1]]
	a = mul(a, pw(b, n - 1))
	return a[0][0]

def F(n):
	a = [1, 2, 3, 4, 32, 123, 43, 2123, 432, 1234, 32123, 43212, 34321, 23432, 123432]
	b = [123432, 234321, 343212, 432123, 321234,
		  123432, 432123, 212343, 432123, 123432,
		  321234, 432123, 343212, 234321, 123432]
	re = 0
	for i in range(15):
#		print S((n + 15 - 1 - i) / 15) * 10 ** len(str(a[i]))
		re += S((n + 15 - 1 - i) / 15) * 10 ** len(str(a[i])) * b[i] + (n + 15 - 1 - i) / 15 * a[i]
		re %= p
	return re

print F(10 ** 14)
