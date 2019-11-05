p = 1117117717
a = [5, 5, 3, 2, 6, 1, 1, 3, 4, 0]
a = [0, 1, 0, 0, 0, 0, 0, 0, 0, 0]
n = 10
r = 0
s = 0
def F(n):
	s = 0
	while n > 1:
		if n % 7 == 0:
			n /= 7
		else:
			s += 7 - n % 7
			n = n / 7 + 1
	return s

for i in range(10):
	s += a[i] * 7 ** i
s = s * (pow(7 ** 10, n / 10, p) - 1) * pow(7 ** 10 - 1, p - 2, p) % p
ans = s - 1
bf = 0
for i in range(1, s):
	bf += F(i)
print 's =', s
t = 1
for i in range(n / 10):
	for j in range(10):
		if s > 0:
			ans = (ans - 6 * t) % p
		s = (s - a[j] * t) % p
		ans = (ans + s * pow(7, p - 2, p) % p * 21) % p
		for k in range(a[j]):
			ans = (ans + t * (6-k)) % p
		ans = (ans + r * a[j]) % p
		r = (r + a[j] * t) % p
		t = t * 7 % p
#ans = (ans + pow(7, n - 1, p) * 6) % p
print r, s, t
print ans, bf