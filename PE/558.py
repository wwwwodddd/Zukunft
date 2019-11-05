f = [1, 2, 3]
for i in range(300):
	f.append(f[-1] + f[-3])

def F(n):
	n *= f[200];
	a = []
	for i in range(300)[::-1]:
		if n >= f[i]:
			n -= f[i]
			a.append(i)
	return len(a)

n = 5000000
s = 0
for i in xrange(1, n + 1):
	s += F(i * i)
	if i % 10000 == 0:
		print i

print s