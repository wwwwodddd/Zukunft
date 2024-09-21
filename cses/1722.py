p = 1000000007
def mul(a, b):
	return [(a[0] * b[0] + a[1] * b[1]) % p, (a[1] * b[0] + a[0] * b[1] + a[1] * b[1]) % p]

def F(n):
	if n == 0:
		return [1, 0]
	elif n & 1:
		a = F(n - 1)
		return mul(a, [0, 1])
	else:
		a = F(n // 2)
		return mul(a, a)

print(F(int(input()))[1])