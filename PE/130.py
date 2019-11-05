def P(x):
	if x < 2:
		return False
	i = 2
	while i * i <= x:
		if x % i == 0:
			return False
		i += 1
	return True
def gcd(x, y):
	if y == 0:
		return x
	return gcd(y, x % y)
cnt = 0
ans = 0
for n in xrange(2, 10000000):
	if gcd(n, 10) > 1:
		continue
	if P(n):
		continue
	if (pow(10, n - 1) - 1) / 9 % n == 0:
#		print n
		ans += n
		cnt += 1
		if cnt == 25:
			break
print ans