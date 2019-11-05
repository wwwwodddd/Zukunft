def P(x):
	if x < 2:
		return False
	i = 2
	while i * i <= x:
		if x % i == 0:
			return False
		i += 1
	return True

a, b, k = 1000000, 1000, 1000
a, b, k = 10**9, 10**5, 10**5
k -= 1
def C(n, m, p):
	if m < 0:
		if n == m:
			return 1
		else:
			return 0
	re = 1
	v = 1
	for i in range(m):
		re = re * (n - i) % p
		v = v * (i + 1) % p
	return re * pow(v, p - 2, p) % p

def d(p, k):
	return (1 - C(p - 1 + k, k, p)) * pow(k, p - 2, p) % p
	ans = 0
	c = 1
	for i in range(1, p):
		c = c * pow(i, p - 2, p) % p
		ans += c
		c = c * (i + k) % p
#		print pow(i, p - 2, p), C(n - i + k - 1, k - 1, p), i - 1 + k - 1, k - 1
		ans %= p
	return (p - ans) % p
#print d(7, 2, 1)
#exit()
def D(a, b, k):
	ans = 0
	for p in range(a, a + b):
		if P(p):
			print a, p, b
			ans += d(p, k)
	return ans


print D(a, b, k)