a = [1, 2, 3, 4, 6, 9, 13, 19, 28, 41]
for i in range(10):
	a.append(a[-1] + a[-3])
def F(a):
	n = len(a)
	s = 0
	z = 0
	for i in range(2, 2 ** n):
		s = [a[j] for j in range(n) if i >> j & 1 > 0]
		if sum(s) > 2 * max(s):
			z += 1
	return z


n = len(a)
#f = [F(a[:i+1]) for i in range(n)]


f = [0, 0, 0, 2, 7, 19, 47, 108, 236, 501, 1045, 2149, 4378, 8869, 17892, 35988, 72254, 144886, 290271, 581207]
f = f[3:]

for i in range(8):
	print '{',
	for j in range(8):
		print f[i + j],
		if j < 7:
			print ',',
	print '},'
