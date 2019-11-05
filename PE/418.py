import fractions
n = 43
p = []
v = [0 for i in range(n)]
for i in range(2, n):
	if v[i] > 0:
		continue
	p.append(i)
	for j in range(i, n, i):
		v[j] = i

print len(p)
c = [0 for i in range(len(p))]
for i in range(len(p)):
	t = n
	while t > 0:
		t /= p[i]
		c[i] += t

print c

