p = 1000000007
t = int(input())
for tt in range(1, t + 1):
	n, m = map(int, input().split())
	print('Case %d: %d' % (tt, n * (1 - pow(1 - pow(n, p - 2, p), m, p)) % p))