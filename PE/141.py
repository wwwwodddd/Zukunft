sq = set(i * i for i in xrange(1, 10 ** 6))
res = set()
for d in xrange(1, 10 ** 6):
	d2 = d * d
	v = set()
	for q in xrange(1, d + 1):
		if d % q == 0:
			v.add(q)
			v.add(d / q)
		if q * q > d:
			break
	for i in v:
		for j in v:
			q = i * j
			if q * q >= d2:
				continue
			if d2 % q == 0:
				n = d2 / q * d + q
				if n in sq:
					if n not in res:
						res.add(n)
						print n
print sorted(list(res))
print sum(res)
