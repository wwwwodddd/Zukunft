a = raw_input()
b = raw_input()
a = list(a)
b = list(b)
n = len(a)
m = len(b)
z = ''
for i in range(n - m + 1):
	flag = True
	for j in range(m):
		if a[i + j] != b[j] and a[i + j] != '?':
			flag = False
	if not flag:
		continue
	c = a[::]
	for j in range(m):
		c[i + j] = b[j]
	for i in range(n):
		if c[i] == '?':
			c[i] = 'a'
	if z == '':
		z = c
	else:
		z = min(z, c)
if z == '':
	print 'UNRESTORABLE'
else:
	print ''.join(z)