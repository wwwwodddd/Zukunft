p = 1000000007
n, m = map(int, input().split())
v = pow(n - 1, p - 2, p)
f = {0 : 0}
def F(x):
	if x in f:
		return f[x]
	i = 2
	s = 0
	while i <= n:
		if i > x:
			j = n
		else:
			j = min(x // (x // i), n)
		s += (j - i + 1) * F(x // i)
		i = j + 1
	f[x] = (s + n) * v % p
	return f[x]
print(F(m))