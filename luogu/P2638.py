def C(n, m):
	r = 1
	for i in range(m):
		r = r * (n - i) / (i + 1)
	return r
n, a, b = map(int, raw_input().split())
print C(a + n, n) * C(b + n, n)