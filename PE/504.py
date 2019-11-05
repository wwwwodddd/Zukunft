import fractions
m = 100
cnt = 0
for i in xrange(1, m + 1):
	print i
	for j in xrange(1, m + 1):
		for k in xrange(1, m + 1):
			for l in xrange(1, m + 1):
				s = (i + k) * (j + l)
				b = fractions.gcd(i, j) + fractions.gcd(j, k) + fractions.gcd(k, l) + fractions.gcd(l, i)
				w = (s + 2 - b) / 2
				sq = int(w ** 0.5)
				if sq * sq == w:
					cnt += 1

print cnt
