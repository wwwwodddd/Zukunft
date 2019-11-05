import sys
from sage.all import *

#print prime_pi(7, 11)
n = 10 ** 12
ans = prime_pi(int(floor(pow(n, 1. / 7))))
for i in xrange(1, int(floor(pow(n, 1. / 3)))):
	if i in Primes():
		ans += prime_pi(n / i / i / i)
ans -= prime_pi(int(floor(pow(n, 1. / 4))))

i = 1
while i ** 3 < n:
	if i in Primes():
		print i
		j = i + 1
		while i * j ** 2 < n:
			if j in Primes():
				ans += prime_pi(n / i / j) - prime_pi(j)
			j = j + 1
	i += 1

print ans