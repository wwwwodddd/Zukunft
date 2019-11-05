f = [1, 2]
for i in range(100):
	f.append(f[-1] + f[-2])

def F(x):
	re = 0
	for i in range(100)[::-1]:
		if x >= f[i]:
			x -= f[i]
			re += 1
	return re

#print F(100)

a = [0 for i in range(100)]
a[1] = 1
for i in range(2, 95):
	a[i] = a[i - 1] + a[i - 2] + f[i - 2]

#print a[:10]
n = 10 ** 17
s = 0
c = 0
for i in range(100)[::-1]:
	if n >= f[i]:
		s += a[i] + c * f[i]
		c += 1
		n -= f[i]

print s

