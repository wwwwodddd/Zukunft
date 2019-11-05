def F(x):
	if x == 0:
		return 1
	return F(x - 1) * x
def C(n, m):
	return F(n) / F(m) / F(n - m)

q = 20
def G(k):
	if k * 10 - q >= 0:
		return F(k * 10) / F(k * 10 - q) * F(70 - q)
	else:
		return 0

f = [G(i) for i in range(8)]
s = 0
for i in range(0, 8):
	for j in range(i):
		f[i] -= f[j] * C(i, j)
#	print i
#	print f[i]
#	print F(70)
	s += f[i] * C(7, i) * i
	

print s * 10 ** 30 / F(70)
print 10 ** 30