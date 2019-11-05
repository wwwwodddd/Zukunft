def F(n, k):
	re = 0
	while n > 0:
		n /= k
		re += n
	return re

def GG(n, k):
	re = 0
	for i in range(1, n + 1):
		re += F(i, k)
	return re

def G(n, k):
	nn = n
	t = 1
	re = 0
	while t <= nn:
		t *= k
		re += t * (n / t) * (n / t - 1) / 2
		re += (n % t + 1) * (n / t)
	return re


def P(x):
	if x < 2:
		return False
	i = 2
	while i * i <= x:
		if x % i == 0:
			return False
		i += 1
	return True

n = 20000
ans = 0
mod = 1000000007
primes = []
for i in range(2, n + 1):
	if P(i):
		primes.append(i)
def D(n):
	re = 1
	for i in primes:
		if i <= n:
			t = (n + 1) * F(n, i)
			t -= 2 * G(n, i)
			re = re * (pow(i, t + 1, mod) - 1) * pow(i - 1, mod - 2, mod) % mod
		else:
			break
	return re

for i in range(1, n + 1):
	if i % 100 == 0:
		print i
	ans = (ans + D(i)) % mod
print ans
