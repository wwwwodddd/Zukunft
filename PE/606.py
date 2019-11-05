from sage.all import *

n = 10 ** 4
z = 0
i = next_prime(0)
while i * i <= n:
	z += prime_pi(n / i) - prime_pi(i)
	i = next_prime(i)
print z

