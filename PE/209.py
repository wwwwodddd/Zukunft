p = [-1 for i in range(64)]
v = [False for i in range(64)]
for i in range(64):
	a = [i >> j & 1 for j in range(6)]
	b = a[1:]
	b.append(a[0] ^ (a[1] & a[2]))
	p[i] = sum(b[j] * 2 ** j for j in range(6))
#print len(set(p))

f = [2, 1]
for i in range(64):
	f.append(f[-1] + f[-2])
z = 1
for i in range(64):
	if v[i]:
		continue
	x = i
	l = 0
	while not v[i]:
		v[i] = True
		i = p[i]
		l += 1
	print l
	z *= f[l]
print z
