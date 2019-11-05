def T(n, k):
	return n * (n * (k - 2) + 4 - k) / 2


def F(a, b, k):
	for i in range(1, 10):
		if T(i, k) * a + b not in s:
			return False
	return True

n = 10 ** 12
sqrtn = int(n ** 0.5)
ans = 0
k = 3
def gao(n, k):
	L = 0
	R = n
	while L < R - 1:
		M = (L + R) / 2
		if M*(k-4)*((k-2)*M*(k-4)+k-4)/2 <= n:
			L = M
		else:
			R = M
	return L
while (2*k-3)*(2*k-3) <= n:
	u = min((sqrtn-1) / (2*k-4), gao(n, k))
#	print 'keke', k, u, u*(k-4)*((k-2)*u*(k-4)+k-4)/2, n
	kk = 2*k-4
	ans += (6*u + 6*kk*u + kk*kk*u + 6*kk*u*u+3*kk*kk*u*u+2*kk*kk*u*u*u) / 6
	ans += (k-4)*(k-4)*u*(1+u)*(1+k-4*u+2*k*u)/12
	k += 2
print ans