a = []
a.append((1, 2, 1, 1))
a.append((2, 6, 2, 2))
a.append((6, 12, 3, 4))
s = 12
t = 4
u = 6
for i in xrange(2, 30000):
	for j in xrange(a[i][0], a[i][1], a[i][2]):
		a.append((s, s + a[i][2] * t, t, u))
		s += a[i][2] * t
		t += 1
		u += a[i][2]


ans = 0
print 'answer'
i = 1
for l, r, x, y in a:
	n = i * i * i
	while l <= n and n < r:
		ans += (n - l) / x + y
		i += 1
		if i == 1000000:
			print ans
			exit()
		n = i * i * i
print ans

#b = [0, 1]
#for i in range(1, 100):
#	b.append(1 + b[i + 1 - b[b[i]]])

#for i in range(len(b)):
#	print i, b[i]