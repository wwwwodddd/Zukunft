def P(x):
	if x < 2:
		return False
	i = 2
	while True:
		if x % i == 0:
			return False
		i += 1
		if i * i > x:
			break
	return True

def C(n, m, p):
	if m > n or m < 0:
		return 0
	if m > n - m:
		m = n - m
	re = 1
	for i in range(m):
		re = re * (n - i) * pow(i + 1, p - 2, p) % p
	return re

def calc(n, m, p):
	re = 1
	while n > 0 or m > 0:
		re = re * C(n % p, m % p, p) % p
		n /= p
		m /= p
	return re

a = []
r = []
for i in range(1000, 5000):
	if P(i):
		a.append(i)
		r.append(calc(10 ** 18, 10 ** 9, i))

#print len(a)
#print r
l = len(a)
ans = 0
for k in range(l):
	print k
	for j in range(k):
		for i in range(j):
			bi = pow(a[j] * a[k], a[i] - 1, a[i] * a[j] * a[k])
			bj = pow(a[i] * a[k], a[j] - 1, a[i] * a[j] * a[k])
			bk = pow(a[i] * a[j], a[k] - 1, a[i] * a[j] * a[k])
			tmp = (bi * r[i] + bj * r[j] + bk * r[k]) % (a[i] * a[j] * a[k])
			ans += tmp
#			exit()
print ans