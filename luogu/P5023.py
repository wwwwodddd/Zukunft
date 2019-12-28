p = 1000000007
n, m = map(int, raw_input().split())
if n > m:
	n, m = m, n
if n == 1:
	print pow(2, m, p)
elif n == 2:
	print 4 * pow(3, m - 1, p) % p
elif n == 3:
	print 112 * pow(3, m - 3, p) % p
else:
	if n == m:
		print pow(384, p - 2, p) * (83 * pow(8, n, p) + 5 * pow(2, n + 7, p)) % p
	else:
		print pow(128, p - 2, p) * (83 * pow(8, n, p) + pow(2, n + 8, p)) * pow(3, m - n - 1, p) % p
