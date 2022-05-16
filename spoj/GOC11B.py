p = 1000000007
for t in range(1, int(input()) + 1):
	n, m = map(int, input().split())
	print('Case %d: %d' % (t, (pow(m, n, p) - pow(m, (n + 1) // 2, p)) % p))