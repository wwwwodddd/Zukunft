from math import gcd
mod = 1000000007
n = 10000000
v = [i for i in range(n + 1)]
for i in range(2, n + 1):
	if v[i] == i:
		for j in range(i, n + 1, i):
			v[j] = v[j] // i * (i - 1)
def phi(x):
	z = 0
	for i in range(1, x + 1):
		if gcd(i, x) == 1:
			z += 1
	return z
def phi2(x):
	if x == 1:
		return 2
	return phi(x) // 2 * 3
def fuck(x):
	if x == 1:
		return 2
	if x % 2 == 0:
		return v[x] * 2
	else:
		return v[x] // 2 * 3
def S(n):
	z = 0
	for d in range(1, n + 1):
		w = 1
		r = pow(2, d, mod)
		for di in range(1, n // d + 1):
			z = (z + w * fuck(di)) % mod
			w = w * r % mod
	return z

# print(S(3))
# print(S(10))
# print(S(1000))
print(S(10000000))
