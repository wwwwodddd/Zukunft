n, k, m = map(int, input().split())
L = 1
R = n + 1
def ok(n, x):
	s = 0
	kk = 0
	while kk < k:
		d = (n - s) // x
		if d <= m:
			return (n - s + m - 1) // m + kk <= k
		t = (n - s - d * x) // d + 1
		t = min(t, k - kk)
		kk += t
		s += t * d
	return s == n
while L < R - 1:
	M = (L + R) // 2
	if ok(n, M):
		L = M
	else:
		R = M
print(L)