import fractions
L = 1864
R = 1909

s = set()
for i in range(L, R + 1):
	for j in range(i):
		s.add(fractions.Fraction(j, i))

print len(s)


