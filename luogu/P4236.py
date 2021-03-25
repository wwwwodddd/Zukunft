t = int(input())
for tt in range(t):
	a, n = map(int, input().split())
	if a & 1:
		print(['wzt', 'lsq'][n & 1], 'Win')
	else:
		n %= a + 1
		print(['wzt', 'lsq'][n & 1 or n == a], 'Win')
