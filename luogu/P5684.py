import collections
n = int(input())
p = 1000000007
c = list(collections.Counter(input()).values())
f = [0 for i in range(n + 1)]
f[0] = 1
for i in range(1, n + 1):
	f[i] = f[i - 1] * i % p
def S(c):
	r = 1
	s = 0
	for i in c:
		r = r * f[i] % p
		s += i
	return f[s] * pow(r, p - 2, p) % p
z = S(c)
o = sum(i % 2 for i in c)
if o <= 1:
	d = [i // 2 for i in c]
	z = (z - S(d)) % p
for i in c:
	z = z * f[i] % p
print(z)