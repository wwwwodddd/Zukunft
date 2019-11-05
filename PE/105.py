ans = 0
for line in open('p105_sets.txt').readlines():
	a = map(int, line.split(','))
	n = len(a)
	z = []
	for i in range(2 ** n):
		c = 0
		s = 0
		for j in range(n):
			if i >> j & 1:
				c += 1
				s += a[j]
		z.append((s, c))
	z.sort()
	test = True
	for i in range(1, 2 ** n):
		if z[i][0] == z[i - 1][0]:
			test = False
		if z[i][1] < z[i - 1][1]:
			test = False
	if test:
		print a
		ans += sum(a)
print ans