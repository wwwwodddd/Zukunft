def S(x):
	return x * (x + 1) * (2 * x + 1) / 6

ans = 0
chongfude = set([])
for i in xrange(1, 10001):
	for j in xrange(1, i):
		s = S(i) - S(j - 1)
		if s >= 10 ** 8:
			continue
		if str(s) == str(s)[::-1]:
			chongfude.add(s)
print sum(chongfude)