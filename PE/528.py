p = 10 ** 9 + 7
def C(n, m):
	r = 1
	for i in range(m):
		r = r * (n - i) * pow(i + 1, p - 2, p) % p
	return r

def F(n, k):
	if n < 0:
		return 0
	return C(n + k, k)

def S(n, k, b):
	a = [b ** i for i in range(1, k + 1)]
#	print a
	ans = 0
	for i in range(2 ** k):
		nn = n
		cnt = 0
		for j in range(k):
			if i >> j & 1:
				nn -= a[j] + 1
				cnt += 1
		if cnt % 2 == 0:
			ans += F(nn, k)
		else:
			ans -= F(nn, k)
	ans %= p
	return ans

print S(14, 3, 2)
print S(200, 5, 3)
print S(1000, 10, 5)

z = 0
for k in range(10, 16):
	z = (z + S(10 ** k, k, k)) % p
print z
## 779027989