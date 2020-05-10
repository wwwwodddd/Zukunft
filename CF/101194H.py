p = 1000000007
for _ in range(1, input() + 1):
	n, m, k = map(int, raw_input().split())
	z = pow(k, n * m, p)
	for i in range(k):
		z += n * m * pow(i, n + m - 2, p) * pow(k, (n - 1) * (m - 1), p)
	print 'Case #%d:' % _, z % p