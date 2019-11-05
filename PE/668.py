from sage.all import *

n = 10 ** 10
z = n
i = next_prime(0)
while i <= n:
	if i * i <= n:
		z -= i
		i = next_prime(i)
	else:
		j = n // (n // i)
		z -= (n // i) * (prime_pi(j) - prime_pi(i - 1))
		i = next_prime(j)
print z

